#include<iostream>
#include<fstream>
#include<string>
class logger{
    private:
        std::ofstream file;
    public:
        logger(const std::string& filename)
        {
            file.open(filename);
        }
        void log(const std::string& message)
        {
            std::cout<<message<<std::endl;
            file<<message<<std::endl;
        }
        ~logger()
        {
            file.close();
        }
};
int main()
{
    logger logger ("log.txt");
    logger.log("Programm started");
    logger.log("logging to file and console");
    return 0;
}
