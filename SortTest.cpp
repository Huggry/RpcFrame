#include <bits/stdc++.h>
using namespace std;

//记忆口诀
//稳定： 冒泡 插入 归并     计数 桶排序 基排序 （JTJ）
//平均时间复杂度    n2 只有冒泡 选择 插入    其余 nlogn

//1 冒泡排序法  稳定   n2
void Bubble(vector<int>& nums){
    bool flag = false;    //优化   

    for(int i = 0; i < nums.size() - 1; i++){                //遍历的次数为  n- 1
        flag = true;
        for(int j = 0; j < nums.size() - 1 - i; j++){      //每次从前向后冒泡，将当前未排序的最大数冒到最后
            if(nums[j] > nums[j + 1]){                     //注意：当冒完以后，新的最大数不一定在队首
                swap(nums[j], nums[j + 1]);
                flag = false;   
            }
        }
        if(flag) break;      //如果某一趟不存在交换的现象，即所有的数都有序，则直接返回  
    }
    return;
}

//2 选择排序法     不稳定   n2      例如 5 5 2 6  
void Select(vector<int>& nums){   
    for(int i = 0; i < nums.size() - 1; i++){
        int minvale = i;
        for(int j = i + 1; j < nums.size(); j++){
            if(nums[j] < nums[minvale]){      
                minvale = j;
            }
        }
        swap(nums[i], nums[minvale]);
    }
    return;
}

//3 插入排序法   稳定    n2        需要移动元素，腾出坑位插入
void Insert(vector<int>& nums){
    for(int i = 1; i < nums.size(); i++){  //将第一个数看做有序数列，后面的数依次插入
        int key = nums[i], j = i - 1;    //注意：j+1才是待排序的数
        while(j >= 0 && nums[j] > key){   //知道找到不大于待排序的数
            nums[j + 1] = nums[j];     //依次向后移动，腾地方
            j--;
        }
        nums[j + 1] = key;       //将待排序的数放下  这个位置移走了
    }
    return;
}

// 4 归并排序  nlogn 
void merge(vector<int>& nums, int leftbegin, int leftend, int rightbegin, int rightend);

void MergSort(vector<int>& nums, int left, int right){
    if(left >= right) return;                  //保留一个元素   将最后的空依次向上返回
    int mid = (right + left) / 2;
    MergSort(nums, left, mid);     //分
    MergSort(nums, mid + 1, right);
    merge(nums, left, mid, mid + 1, right);    //治
} 

void merge(vector<int>& nums, int leftbegin, int leftend, int rightbegin, int rightend){    //合并两个子集
    vector<int> temp(rightend - leftbegin + 1, 0);
    int k = 0, i = leftbegin, j = rightbegin;
    while(i <= leftend && j <= rightend){  //有一个到达末尾，终止递归
        if(nums[i] <= nums[j]){
            temp[k++] = nums[i++];  //先赋值，再增加1
        }else{
            temp[k++] = nums[j++];
        }
    }
    while(i <= leftend)   temp[k++] = nums[i++];
    while(j <= rightend)  temp[k++] = nums[j++];

    k = 0, i = leftbegin;     
    while(i <= rightend)  nums[i++] = temp[k++];      //因为这里的i++  导致代码错误，我找了好久
    return;
}

//5 

void solve(vector<int>& nums){
    

    return;
}



int main(){
    int n; 
    cin >> n;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    //Bubble(nums);
    //Select(nums);
    //Insert(nums);
    MergSort(nums, 0, nums.size() - 1);
    for(int i : nums){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}