#include <bits/stdc++.h>
using namespace std;

//24年蚂蚁春招 支付宝消费打折题
int main(){
    int n, k;
    cin >> n >> k;
    vector<double> goods(n, 0);
    for(int i = 0; i < n; i++){
        cin >> goods[i];
    }

    string str;
    cin >> str;
    for(int i = 0; i < n; i++){
        if(str[i] == '1'){
            goods[i] = goods[i] * 0.95;
        }
    }
    
    //特别注意：
    //由于价格和购买物品的数量是成正比例关系的，所以这里不需要用dp
    //另外，价格是doouble类型，不能用来dp数组的下标，会报错 
    sort(goods.begin(), goods.end(), [](const double& a, const double& b){return a < b;});
    double sum = 0;
    int cnt = 0;

    for(int i = 0; i < n; i++){
        sum += goods[i];
        if(sum > k){
            break;
        }
        cnt++;
    }

    cout << cnt << endl;
    

    return 0;
}