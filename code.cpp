#include <vector>
#include <unordered_map>
#include <math.h>
#include <string.h>

namespace
{
    // see if any two values in vector as have given value v as product
    bool prod(vector<int> const & as,  const int v)
    {
        std::unordered_map<int, int> maybes;
        for(int a : as)
        {
            int ratio = v/a;
            if (ratio * a != v)
            {
                continue; // not a factor so can ignore, this constrains the 'maybes' hashmap to a logarithmic maximum (nature of factors)
            }

            if (maybes.find(a) != maybes.end())
            {
                return true;
            }

            maybes[ratio] = a;
        }

        return false;
    }

    // see if any two values in as, sum to given value v
    bool foo(vector<int> const & as,  const int v)
    {
        if (v == 0)
        {
            return true; // TODO special case this one
        }
        bool bar[v];
        memset(bar, false, v * sizeof(bool));
        for(int a : as)
        {
            if (a > v)
            {
                continue;
            }
            
            if (bar[v - a])
            {
                return true;
            }
            
            bar[a] = true;
        }
        
        return false;
    }
}