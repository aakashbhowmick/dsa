#include <vector>

template <typename T>
void make_min_heap(std::vector<T>& arr)
{
    size_t size = arr.size();
    for(size_t i=size/2; i > 0; --i)
    {
        size_t iparent = i-1;
        while(true)
        {
            size_t ileft_child  = 2*iparent+1;
            size_t iright_child = 2*iparent+2;

            size_t ismallest = iparent;
            if(ileft_child < size && arr[ileft_child] < arr[ismallest])
                ismallest = ileft_child;
            if(iright_child < size && arr[iright_child] < arr[ismallest])
                ismallest = iright_child;

            if(ismallest == iparent)
                break;

            std::swap(arr[ismallest], arr[iparent]);
            iparent = ismallest;
        }
    }
}

template <typename T>
bool check_min_heap(const std::vector<T>& arr)
{
    size_t size = arr.size();
    for(size_t i=0; i < arr.size(); ++i)
    {
        size_t ileft_child  = 2*i+1;
        size_t iright_child = 2*i+2;

        if(ileft_child < size && arr[ileft_child] < arr[i])
            return false;

        if(iright_child < size && arr[iright_child] < arr[i])
            return false;
    }

    return true;
}
