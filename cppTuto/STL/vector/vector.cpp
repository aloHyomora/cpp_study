#include <iostream>

using namespace std;

#include <vector>
#include <list>
// 특정 기준에 의해 정렬됨 -> 연관 컨테이너

int main()
{
#pragma region VectorDocs
    vector<int> v{ 1,2,3,4,5 };
    // size (resize)
    // capacity (reserve)
    // 삽입, 삭제
    // - 시작 0(N) : 시작에 삽입하고 값을 뒤로 밀어야됨.
    // - 중간 0(N)
    // - 끝 0(1)
    // push_back, front, back, remove

    // size(실제 데이터 크기) vs capacity(할당된 공간)
    // reserve를 먼저 때리고 작업하는 이유 : 이사 비용을 아끼고 메모리 파편화를 막을 수 있다.

    // 데이터를 push_back을 한다. 
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    int a = v.front(); // 0(1)
    int b = v.back();  // 0(1)

    // 앞에 추가하는 건 느리게 동작하니 애초에 만들어두지 않았다.

    // 순회
    const int size = v.size();
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << endl;
    }

    // 초기화
    vector<int> v1(5);
    vector<int> v2(5, -1);
    vector<int> v3{ 1,2,3,4,5 }; // 실제 데이터는 힙에 있음.

    vector<int> v4 = v3; // 값의 복사가 일어남.
    v4[0] = 100;

    // 복사 비용을 아끼고 싶다면?
    /*void Test(vector<int>& v) {

    }*/

    // clear()를 했을 때 size와 capacity는 어떻게 출력될까?
    // => 데이터는 변화 없음.
    v4.clear();

    // 상황에 따라서 capacity를 줄이고 싶다면?
    // 빈 벡터로 스왑, 실제로 이렇게 사용하는 사람은 없다. 이 정도 메모리는 영향이 미미하다.
    vector<int>().swap(v4);

    // iterator ? 반복자 포인터?
    {
        vector<int> v{ 1,2,3,4,5 };

        int* ptr = &v[0];
        int value = *ptr;

        // 다음 데이터로 넘어감(=4바이트 만큼 이동)
        ptr++;

        // 다다음 데이터
        ptr += 2;
    }

#pragma endregion

#pragma region iterator
    {
        cout << endl;
        cout << "Iterator " << endl;
        vector<int> v{ 1,2,3,4,5 };
                    
        // iterator -> 위치를 가리키는 포인터
        vector<int>::iterator it = v.begin();
        vector<int>::iterator itend = v.end();

        while (it != itend)
        {
            cout << *it << endl;
            it++;
        }

        for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
            int data = *it;
            cout << data << endl;
        }

    }
    {
        // 순회하면서 삭제하기
        cout << endl;
        vector<int> v{ 1,2,3,4,5 };


        for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
        {
            int value = *it;
            if (value % 2 == 0)
                it = v.erase(it);
            else // 중요!
                it++;
        }

        for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
            cout << *it << endl;
        }
    }
#pragma endregion
    
#pragma region list
    // 노드 기반

    // size (resize)
    // capacity (reserve)
    // 삽입/ 삭제
    // - 시작 0(1)
    // - 중간 0(1) << 조건부
    // - 끝   0(1)
    // front 0(1), back0(1), push_front0(1), push_back0(1)
    // remove

    list<int> li{ 1,2,3,4,5 };
    
    li.push_front(100);
    li.push_back(101);

    li.insert(li.end(), 1);

    list<int>::iterator it = li.insert(li.end(), 1);

    // 순회
    for (list<int>::iterator it1 = li.begin(); it != li.end(); it++)
    {
        int value = *it1;
        if (value == 3) break;
        cout << value << endl;
    }

    // end 까지 순회하지 않았다. 중간에 탈출했다.
    if (it != li.end())
    {

    }



#pragma endregion
 
#pragma region auto
    // auto
    // 장점
    // - 템플릿이랑 엮어서 사용할 때 유용
    // - 타이핑(::iterator)같은 타이핑 낭비가 줄어든다.
    // 단점
    // - 가독성이 좋지 않다.
    {
        int a = 3;
        double c = 123.324;
        const char* e = "alohyomora";
    }
    {
        auto a = 3;
        auto c = 123.324;
        auto e = "alohyomora";
    }

    // auto는 일종의 조커 카드
    // 형식 연역(type deduction) -> 예측한다. 때려맞춘다.

    int a = 3;
    int& ref = a;
    const int cst = a;
    // 주의! auto는 const, &는 떼고 추론한다.
    auto ref2 = ref;
    auto cst2 = cst;

    // &, const를 붙여 컴파일러에게 알려준다.
    auto& ref3 = ref;
    const auto cst3 = cst;


#pragma endregion
}


