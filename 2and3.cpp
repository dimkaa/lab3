#include "sdt.h"
enum error {er_temp,er_scale,no_er};
error convert(double temperature, char from, char to, double& result);

int main()
{
    using namespace std;
    double degrees,total;
    char scale;
    vector<double>temp_tran;
    while (cout<<"Please enter the temperature = ",cin>> degrees >> scale)
    {
        switch(convert(degrees,scale,'K',total))
        {
        case er_scale:
        {
            cerr<<"Unknown scale!"<<endl;
            break;
        }
        case er_temp:
        {
            cerr<<"Temperature below absolute zero!"<<endl;
            break;
        }
        case no_er:
        {
            temp_tran.push_back(total);
            break;
        }
        default:
        {
            cerr<<"Unknown error!"<<endl;
            break;
        }
        }
    }
    cout<< fixed;
    cout.precision(1);
    for (double x:temp_tran)
    {
        cout<<"Kelvin = "<< x <<"\t Celsius = "<< x-273.15<<"\t Fahrenheit = "<< ((x-273.15)*1.8+32) <<endl;
    }
}
error convert(double temperature, char from, char to, double&result) //Объявлениефункции
{
    switch(from)
    {
    case'K':
        if (temperature>=0)
        {
            switch(to)
            {
            case'K':
            {
                result=temperature;
                return no_er;
                break;
            }
            case'C':
            {
                result=temperature-273;
                return no_er;
                break;
            }
            case'F':
            {
                result=temperature-459.67;
                return no_er;
                break;
            }
            default:
            {
                return er_scale;
                break;
            }
            }
        }
        else
        {
            return er_temp;
            break;
        }
    case'C':
        if (temperature>=-273.15)
        {
            switch(to)
            {
            case'C':

            default:
            {
                return er_scale;
            }
            }
        }
