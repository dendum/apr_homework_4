#include "c_forward_list.cpp"

int main() {
    ForwardList<int> firstList;
    firstList.push_front(1);
    firstList.push_front(2);
    firstList.push_front(3);

    ForwardList<int> secondList = {1, 2, 3, 4, 5};
    ForwardList<int> thirdList;
    thirdList = std::move(firstList);

    firstList.iterate(); // {}
    secondList.iterate(); // 5 4 3 2 1
    thirdList.iterate(); // 3 2 1

}