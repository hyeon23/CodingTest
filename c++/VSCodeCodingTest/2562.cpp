#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // int arr[9];
    // int maxvalue, maxindex;
    // for (size_t i = 0; i < 9; ++i)
    // {
    //     cin >> arr[i];
    //     if (i == 0)
    //     {
    //         maxvalue = arr[0];
    //         maxindex = i;
    //     }
    //     else
    //     {
    //         if (arr[i - 1] < arr[i])
    //         {
    //             maxvalue = arr[i];
    //             maxindex = i;
    //         }
    //     }
    // }

    // cout << maxvalue << endl;
    // cout << maxindex + 1;

    vector<int> vec;
    int maxvalue, maxindex;
    for (size_t i = 0; i < 9; ++i)
    {
        int x;
        cin >> x;
        vec.push_back(x);

        if (i == 0)
        {
            maxvalue = vec[0];
            maxindex = i;
        }
        else
        {
            if (maxvalue < vec[i])
            {
                maxvalue = vec[i];
                maxindex = i;
            }
        }
    }

    cout << maxvalue << endl;
    cout << maxindex + 1;

    return 0;
}