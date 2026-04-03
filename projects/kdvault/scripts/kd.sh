#!/bin/bash
# Color Definitions
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
BOLD='\033[1m'
NC='\033[0m'

# 1. Remember exactly where the user is standing RIGHT NOW
USER_START_DIR=$(pwd)

# 2. Find the folder where THIS script is located
SCRIPT_DIR=$(dirname "$(readlink -f "$0")")

# 3. Go to the Parent folder
PROJECT_DIR="$SCRIPT_DIR/.."
cd "$PROJECT_DIR" || exit

# 4. Define the Vault
VAULT_DIR="$HOME/.kdvault_storage"
APP="./kdvault"

echo -e "${CYAN}${BOLD}               KD-VAULT SYSTEM ${NC}"

# 5. Environment Check
if [ ! -d "$VAULT_DIR" ]; then
    mkdir -p "$VAULT_DIR"
    chmod 700 "$VAULT_DIR"
fi

# 6. Build
echo -e "${YELLOW}[BUILD]${NC} Checking for code updates..."
make

# 7. Security: Unlock (FIXED GLITCH HERE)
echo -e "${GREEN}              Opening kd vault ...${NC}"

# Check if there are any files to unlock first
if [ -n "$(ls -A "$VAULT_DIR" 2>/dev/null)" ]; then
    # We use the 'if !' check. If sudo fails or is canceled (Ctrl+C), the script exits.
    if ! sudo chattr -i "$VAULT_DIR"/* 2>/dev/null; then
        echo -e "${RED}${BOLD}\n[ERROR] Authentication failed or canceled. Access Denied.${NC}"
        exit 1
    fi
else
    # If the vault is empty, we still call sudo to "pre-authenticate" the user
    # so they can add new files later without being asked for a password again.
    if ! sudo true; then
        echo -e "${RED}${BOLD}\n   [ERROR] Authentication failed. Exiting.${NC}"
        exit 1
    fi
fi

# 8. Run the App
if [ -f "$APP" ]; then
    $APP "$USER_START_DIR"
else
    echo -e "${RED}[ERROR] Executable not found at $PROJECT_DIR/$APP${NC}"
    exit 1
fi

# 9. Security: Re-lock
echo -e "${RED}           ***Locking kdvault now***${NC}"
# Only try to lock if the directory isn't empty
if [ -n "$(ls -A "$VAULT_DIR" 2>/dev/null)" ]; then
    sudo chattr +i "$VAULT_DIR"/* 2>/dev/null
fi