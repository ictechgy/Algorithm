#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int n;
    scanf("%d", &n);
    //소수인지 아닌지 처음부터 체크하면서 원하는 차례의 숫자를 찾는건 굉장히 비효율적인 것 같다..
    //2, 3, 5를 제외한 소수인 것들과 그 배수들을 건너뛰면 될거같기도 한데..
    //소수를 찾는데에는 제곱근까지 나눠보는 방법도 있고 배열을 가지고 2부터 배수들을 체크하여 찾는 방법도 있고.. 
    //아니면 2, 3, 5의 값으로만 나누어지는지 본다거나..해야하나..?
    
    //2, 3, 5의 숫자 조합을 이용한 수들만 셈하여 나가는게 가장 괜찮아보이는데..나누어서 확인하는 것보다. 
    //가장 큰 수인 85~~값까지 배열을 만들어서 소수인지 아닌지 어떤 소수의 곱으로 이루어져 있는지 체크하기에는
    //배열공간의 공간복잡도가 너무 커진다. 

    int arr[1501] = {0, 1, 2, 3, 4, 5, };   
    //2, 3, 5의 곱들로만 배열을 채우는 방식? 아니면 원하는 인덱스까지 조건을 충족하는지 수를 늘리고, 2, 3, 5로 나눠보면서 조건 만족 시 값을 추가..? 
    //아니면 2, 3, 5에 대해 지수를 각각 0으로 부여한 후 000, 001, 010 과 같이 지수 부여해가며 곱셈값 계산한 뒤 추가하는 방식? 
    
    
    //어렵다.. 이것도 생각하지 못했다.
    int p2, p3, p5, ptr, num2, num3, num5, min;
    p2 = p3 = p5 = ptr = 1;
    int nums[1501] = {0, 1};
    while(nums[n] == 0){
        ++ptr;  //값 넣을 공간에 대한
        num2 = nums[p2]*2;
        num3 = nums[p3]*3;
        num5 = nums[p5]*5;
        if(num2 <= num3 && num2 <= num5) min = num2;
        else if(num3 <= num2 && num3 <= num5) min = num3;
        else min = num5;

        nums[ptr] = min;
        if(min == num2) p2++;
        if(min == num3) p3++;
        if(min == num5) p5++;
    }
    printf("%d\n", nums[n]);

    return 0;
}

//
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int a[1501];
int main(){
    int n, i, p2, p3, p5, min = 2147000000;
    scanf("%d", &n);
    a[1] = 1;
    p2 = p3 = p5 = 1;
    for(i = 2; i <= n; i++){
        if(a[p2]*2 < a[p3]*3) min = a[p2]*2;
        else min = a[p3]*3;
        if(a[p5]*5 < min) min = a[p5]*5;
        
        if(a[p2]*2 == min) p2++;
        if(a[p3]*3 == min) p3++;
        if(a[p5]*5 == min) p5++;

        a[i] = min;
    }
    printf("%d\n", a[n]);

    return 0;
}