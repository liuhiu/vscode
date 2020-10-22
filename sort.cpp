#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int partition(vector<int>& vec, int left,int right){
    int p = vec[left];
    int i = left+1;
    int j = right;
    while(true){
        while(i <=right && vec[i] <= p) i++;
        while(j >= left+1 && vec[j] >=p) j--;
        if(i >= j) break;
        swap(vec[i],vec[j]);
        i++;
        j--;
    }
    swap(vec[left],vec[j]);
    return j;
}
void merge(vector<int>& vec,int left, int mid, int right){
     vector<int> tmp(right-left+1);
     for(int i = left; i <= right; ++i){
         tmp[i-left] = vec[i];
     }
     int i = left;
     int j = mid+1;
     for(int k = left; k <= right; ++k){
         if(i > mid){
             vec[k] = tmp[j-left];
             j++;
         }else if(j > right){
             vec[k] = tmp[i-left];
             i++;
         }else if(tmp[i-left] > tmp[j-left]){
             vec[k] = tmp[j-left];
             j++;
         }else{
             vec[k] = tmp[i-left];
             i++;
         }
     }
}

void mergesort(vector<int>& vec,int left, int right){
    if(left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergesort(vec,left,mid);
    mergesort(vec,mid+1,right);
    merge(vec,left,mid,right);
}

void quicksort(vector<int>& vec,int left, int right){
    if(left >= right){
        return;
    }
    int p = partition(vec,left,right);
    quicksort(vec,left,p-1);
    quicksort(vec,p+1,right);
}

void insertsort(vector<int>& vec){
    int j = 0;
    for(int i = 0; i < vec.size(); ++i){  // 或int i = 1
        int tmp = vec[i];
        for(j = i; j > 0 && vec[j-1] > tmp; --j){
            vec[j] = vec[j-1];
        }
        vec[j] = tmp;
    }
}

int main()
{
    vector<int> vec = {1,5,4,6,46,32,0,0,0,11};
    int n = vec.size();
    //quicksort(vec,0,n-1);
    //mergesort(vec,0,n-1);
    //insertsort(vec);
    for(int i = 0; i < n; ++i){
        cout << vec[i] << "  ";
    }
    cout << endl;


    vector<int> data;
	for (int i = 0; i < 10; i++)
	{
		data.push_back(i);  // 0,1,2,3,4,5,6,7,8,9
	}
    vector<int>::iterator itr =  remove(data.begin(),data.end(),2);
                              // remove 最后一位是删除哪个元素，而不是位置
    cout << *itr << endl;  // 9
    cout << *(itr-1) << endl; // 9
    cout << *(itr-2) << endl; // 8
    cout << itr-data.begin() <<endl; // 9
    if(itr+1 == data.end()){
        cout << "yes" << endl;  // yes
    }
    //data.erase(data.end()-1);
    for(int i = 0; i < data.size(); ++i){
        cout << data[i] << "  "; // 0,1,3,4,5,6,7,8,9,9
    }
    cout << endl;
    itr = data.erase(data.begin()+1);
    cout << *itr << endl; // 3
    for(int i = 0; i < data.size(); ++i){
        cout << data[i] << "  "; // 0,3,4,5,6,7,8,9,9
    }

    return 0;
}