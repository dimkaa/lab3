Minmax.cpp
#include "convert.h"
#include "sdt.h"



voidminimax(const vector<Temperature> temp_res, Temperature &minimum, Temperature &maximum, Temperature &average)
{
usingnamespace std;
    average.value=0;
    maximum.value=0;
minimum=temp_res[0];
for (Temperature x:temp_res)
    {
if (x < minimum)
        {
            minimum=x;
        }
elseif (x>maximum)
        {
            maximum=x;
        }
        average+=x;
    }
average=average/temp_res.size();
}

