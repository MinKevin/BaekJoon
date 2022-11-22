#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string buf = "a" + 1;
    cout << buf << '\n';// ?臾닿?? 異?λ吏 ??

    /*
    * 
    vector<int> v3 = {1,2,3};
    vector<int> v4;
    v4 = v3;
    v4[2] = 10;
    cout << v3[2];
    */

    /*
    int numArr[3][4] = {    // ?몃? 3, 媛濡 4 ?ш린? int? 2李⑥ 諛곗????
        { 11, 22, 33, 44 },
        { 55, 66, 77, 88 },
        { 99, 110, 121, 132 }
    };
    int(*numPtr)[4] = numArr;
    printf("%p\n", *numPtr); // 002BFE5C: 2李⑥ 諛곗??ъ명곕? ?李몄“?硫??몃? 泥?踰吏몄 二쇱媛 ???
                             // 而댄⑦곕??? ?ㅽ? ?留???щ쇱?
    printf("%p\n", *numArr); // 002BFE5C: 2李⑥ 諛곗댁 ?李몄“?硫??몃? 泥?踰吏몄 二쇱媛 ???
                             // 而댄⑦곕??? ?ㅽ? ?留???щ쇱?
    printf("%d\n", numPtr[2][1]);    // 110: 2李⑥ 諛곗??ъ명곕 ?몃깆ㅻ? ?洹쇳 ? ??
    printf("%d\n", sizeof(numArr));  // 48: sizeof濡 2李⑥ 諛곗댁 ?ш린瑜?援ы硫?諛곗댁?硫紐⑤━?
                                     // 李⑥??? 怨듦???異?λ?
    printf("%d\n", sizeof(numPtr));  // 4 : sizeof濡 2李⑥ 諛곗??ъ명곗 ?ш린瑜?
                                     // 援ы硫??ъ명곗 ?ш린媛 異?λ?64鍮?몃쇰㈃ 8)
    */
    return 0;
}