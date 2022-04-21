#define debug(x) cout << "[DEBUG] (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ") " << #x << " := " << (x) << "\n";

#include <iostream>
#include "linked_list.h"
#include "tests.h"

using std::cout;

namespace {
     bool test_passed = true;
}

bool test_create() {
     MyList list = MyList();
     assert(list.size() is 0);
     assert(list.head() is nullptr);

     END_TEST
}

bool test_add() {
     MyList list = MyList();
     assert(list.size() is 0);
     assert(list.head() is nullptr);

     list.add("A", 1);
     {
          const MyNode* head = list.head();
          assert(list.size() is 1);
          assert(head is_not nullptr);
          assert(head->name is "A");
          assert(head->prev is nullptr);
          assert(head->next is nullptr);
     }

     list.add("B", 2);
     {
          assert(list.size() is 2);
          const MyNode* head = list.head();
          assert(head is_not nullptr);
          assert(head->name is "A");
          assert(head->prev is nullptr);
          assert(head->next is_not nullptr);
          assert(head->next->name is "B");
          assert(head->next->prev is_not nullptr);
          assert(head->next->prev is head);
          assert(head->next->next is nullptr);
     }

     list.add("C", 3);
     {
          assert(list.size() is 3);
          const MyNode* head = list.head();
          assert(head is_not nullptr);
          assert(head->name is "A");
          assert(head->score is 1);
          assert(head->prev is nullptr);
          assert(head->next is_not nullptr);
          assert(head->next->name is "B");
          assert(head->next->score is 2);
          assert(head->next->prev is_not nullptr);
          assert(head->next->prev is head);
          assert(head->next->next is_not nullptr);
          assert(head->next->next->name is "C");
          assert(head->next->next->score is 3);
          assert(head->next->next->next is nullptr);
          assert(head->next->next->prev is head->next);
     }

     END_TEST
}

bool test_clear_empty() {
     MyList list = MyList();
     assert(list.size() is 0);
     assert(list.head() is nullptr);

     list.clear();
     {
          assert(list.size() is 0);
          assert(list.head() is nullptr);
     }

     END_TEST
}

bool test_clear_not_empty() {
     MyList list = MyList();
     list.add("A", 1);
     list.add("B", 2);
     list.add("C", 3);
     list.add("D", 4);
     list.add("E", 5);
     {
          assert(list.size() is 5);
          const MyNode* head = list.head();
          assert(head is_not nullptr);
          assert(head->name is "A");
          assert(head->score is 1);
          assert(head->prev is nullptr);
          assert(head->next is_not nullptr);
          assert(head->next->name is "B");
          assert(head->next->score is 2);
          assert(head->next->prev is_not nullptr);
          assert(head->next->prev is head);
          assert(head->next->next is_not nullptr);
          assert(head->next->next->name is "C");
          assert(head->next->next->score is 3);
          assert(head->next->next->next is_not nullptr);
          assert(head->next->next->prev is head->next);
     }

     list.clear();
     {
          assert(list.size() is 0);
          assert(list.head() is nullptr);
     }

     END_TEST
}

bool test_remove_head() {
     MyList list = MyList();
     list.add("A", 1);
     list.add("B", 2);
     list.add("C", 3);

     {
          assert(list.size() is 3);
          const MyNode* head = list.head();
          assert(head is_not nullptr);
          assert(head->name is "A");
          assert(head->score is 1);
          assert(head->prev is nullptr);
          assert(head->next is_not nullptr);
          assert(head->next->name is "B");
          assert(head->next->score is 2);
          assert(head->next->prev is_not nullptr);
          assert(head->next->prev is head);
          assert(head->next->next is_not nullptr);
          assert(head->next->next->name is "C");
          assert(head->next->next->score is 3);
          assert(head->next->next->next is nullptr);
          assert(head->next->next->prev is head->next);
     }

     {
          assert(list.remove("A") is true);
          assert(list.size() is 2);
          const MyNode* head = list.head();
          assert(head is_not nullptr);
          assert(head->prev is nullptr);
          assert(head->next is_not nullptr);
          assert(head->name is "B");
          assert(head->score is 2);
     }

     END_TEST
}

bool test_remove_tail() {
     MyList list = MyList();
     list.add("A", 1);
     list.add("B", 2);
     list.add("C", 3);

     {
          assert(list.size() is 3);
          const MyNode* head = list.head();
          assert(head is_not nullptr);
          assert(head->name is "A");
          assert(head->score is 1);
          assert(head->prev is nullptr);
          assert(head->next is_not nullptr);
          assert(head->next->name is "B");
          assert(head->next->score is 2);
          assert(head->next->prev is_not nullptr);
          assert(head->next->prev is head);
          assert(head->next->next is_not nullptr);
          assert(head->next->next->name is "C");
          assert(head->next->next->score is 3);
          assert(head->next->next->next is nullptr);
          assert(head->next->next->prev is head->next);
     }

     {
          assert(list.remove("C") is true);
          assert(list.size() is 2);
          const MyNode* head = list.head();
          assert(head is_not nullptr);
          assert(head->prev is nullptr);
          assert(head->next is_not nullptr);
          assert(head->name is "A");
          assert(head->score is 1);
     }

     END_TEST
}

bool test_remove_middle() {
     MyList list = MyList();
     list.add("A", 1);
     list.add("B", 2);
     list.add("C", 3);

     {
          assert(list.size() is 3);
          const MyNode* head = list.head();
          assert(head is_not nullptr);
          assert(head->name is "A");
          assert(head->score is 1);
          assert(head->prev is nullptr);
          assert(head->next is_not nullptr);
          assert(head->next->name is "B");
          assert(head->next->score is 2);
          assert(head->next->prev is_not nullptr);
          assert(head->next->prev is head);
          assert(head->next->next is_not nullptr);
          assert(head->next->next->name is "C");
          assert(head->next->next->score is 3);
          assert(head->next->next->next is nullptr);
          assert(head->next->next->prev is head->next);
     }

     {
          assert(list.remove("B") is true);
          assert(list.size() is 2);
          const MyNode* head = list.head();
          assert(head is_not nullptr);
          assert(head->name is "A");
          assert(head->score is 1);
          assert(head->prev is nullptr);
          assert(head->next is_not nullptr);
          assert(head->next->name is "C");
          assert(head->next->score is 3);
          assert(head->next->prev is_not nullptr);
          assert(head->next->prev is head);
          assert(head->next->next is nullptr);
     }


     END_TEST
}

bool test_remove_empty() {
     MyList list = MyList();
     assert(list.size() is 0);
     assert(list.head() is nullptr);

     {
          assert(list.remove("A") is false);
          assert(list.size() is 0);
          assert(list.head() is nullptr);
     }

     END_TEST
}

bool test_remove_fail() {
     MyList list = MyList();
     list.add("A", 1);
     list.add("B", 2);
     list.add("C", 3);

     {
          assert(list.size() is 3);
          const MyNode* head = list.head();
          assert(head is_not nullptr);
          assert(head->name is "A");
          assert(head->score is 1);
          assert(head->prev is nullptr);
          assert(head->next is_not nullptr);
          assert(head->next->name is "B");
          assert(head->next->score is 2);
          assert(head->next->prev is_not nullptr);
          assert(head->next->prev is head);
          assert(head->next->next is_not nullptr);
          assert(head->next->next->name is "C");
          assert(head->next->next->score is 3);
          assert(head->next->next->next is nullptr);
          assert(head->next->next->prev is head->next);
     }

     {
          assert(list.remove("5") is false);
          assert(list.size() is 3);
          const MyNode* head = list.head();
          assert(head is_not nullptr);
          assert(head->name is "A");
          assert(head->score is 1);
          assert(head->prev is nullptr);
          assert(head->next is_not nullptr);
          assert(head->next->name is "B");
          assert(head->next->score is 2);
          assert(head->next->prev is_not nullptr);
          assert(head->next->prev is head);
          assert(head->next->next is_not nullptr);
          assert(head->next->next->name is "C");
          assert(head->next->next->score is 3);
          assert(head->next->next->next is nullptr);
          assert(head->next->next->prev is head->next);
     }

     END_TEST
}

bool test_remove_singleton() {
     MyList list = MyList();
     list.add("A", 1);
     {
          assert(list.size() is 1);
          const MyNode* head = list.head();
          assert(head is_not nullptr);
          assert(head->next is nullptr);
          assert(head->prev is nullptr);
          assert(head->name is "A");
          assert(head->score is 1);
     }

     {
          assert(list.remove("A") is true);
          const MyNode* head = list.head();
          assert(list.size() is 0);
          assert(head is nullptr);
     }

     END_TEST
}

bool test_insert_head() {
     MyList list = MyList();
     list.add("A", 1);
     list.add("B", 2);
     list.add("C", 3);

     {
          assert(list.size() is 3);
          const MyNode* head = list.head();
          assert(head is_not nullptr);
          assert(head->name is "A");
          assert(head->score is 1);
          assert(head->prev is nullptr);
          assert(head->next is_not nullptr);
          assert(head->next->name is "B");
          assert(head->next->score is 2);
          assert(head->next->prev is_not nullptr);
          assert(head->next->prev is head);
          assert(head->next->next is_not nullptr);
          assert(head->next->next->name is "C");
          assert(head->next->next->score is 3);
          assert(head->next->next->next is nullptr);
          assert(head->next->next->prev is head->next);
     }

     list.insert("Z", 26, 0);
     {
          assert(list.size() is 4);
          const MyNode* head = list.head();
          assert(head is_not nullptr);
          assert(head->name is "Z");
          assert(head->score is 26);
          assert(head->prev is nullptr);
          assert(head->next is_not nullptr);

          assert(head->next->name is "A");
          assert(head->next->score is 1);
          assert(head->next->prev is_not nullptr);
          assert(head->next->prev is head);
          assert(head->next->next is_not nullptr);

          assert(head->next->next->name is "B");
          assert(head->next->next->score is 2);
          assert(head->next->next->next is_not nullptr);
          assert(head->next->next->prev is head->next);

          assert(head->next->next->next->name is "C");
          assert(head->next->next->next->score is 3);
          assert(head->next->next->prev is_not nullptr);
          assert(head->next->next->prev is head->next);
          assert(head->next->next->next->next is nullptr);
          assert(head->next->next->next->prev is_not nullptr);
          assert(head->next->next->next->prev is head->next->next);
     }

     END_TEST
}

bool test_insert_tail() {
     MyList list = MyList();
     list.add("A", 1);
     list.add("B", 2);
     list.add("C", 3);

     {
          assert(list.size() is 3);
          const MyNode* head = list.head();
          assert(head is_not nullptr);
          assert(head->name is "A");
          assert(head->score is 1);
          assert(head->prev is nullptr);
          assert(head->next is_not nullptr);
          assert(head->next->name is "B");
          assert(head->next->score is 2);
          assert(head->next->prev is_not nullptr);
          assert(head->next->prev is head);
          assert(head->next->next is_not nullptr);
          assert(head->next->next->name is "C");
          assert(head->next->next->score is 3);
          assert(head->next->next->next is nullptr);
          assert(head->next->next->prev is head->next);
     }

     list.insert("Z", 26, 3);
     {
          assert(list.size() is 4);
          const MyNode* head = list.head();
          assert(head is_not nullptr);
          assert(head->name is "A");
          assert(head->score is 1);
          assert(head->prev is nullptr);
          assert(head->next is_not nullptr);

          assert(head->next->name is "B");
          assert(head->next->score is 2);
          assert(head->next->prev is_not nullptr);
          assert(head->next->prev is head);
          assert(head->next->next is_not nullptr);

          assert(head->next->next->name is "C");
          assert(head->next->next->score is 3);
          assert(head->next->next->next is_not nullptr);
          assert(head->next->next->prev is head->next);

          assert(head->next->next->next->name is "Z");
          assert(head->next->next->next->score is 26);
          assert(head->next->next->prev is_not nullptr);
          assert(head->next->next->prev is head->next);
          assert(head->next->next->next->next is nullptr);
          assert(head->next->next->next->prev is_not nullptr);
          assert(head->next->next->next->prev is head->next->next);
     }
     END_TEST
}

bool test_insert_middle() {
     MyList list = MyList();
     list.add("A", 1);
     list.add("B", 2);
     list.add("C", 3);

     {
          assert(list.size() is 3);
          const MyNode* head = list.head();
          assert(head is_not nullptr);
          assert(head->name is "A");
          assert(head->score is 1);
          assert(head->prev is nullptr);
          assert(head->next is_not nullptr);
          assert(head->next->name is "B");
          assert(head->next->score is 2);
          assert(head->next->prev is_not nullptr);
          assert(head->next->prev is head);
          assert(head->next->next is_not nullptr);
          assert(head->next->next->name is "C");
          assert(head->next->next->score is 3);
          assert(head->next->next->next is nullptr);
          assert(head->next->next->prev is head->next);
     }

     list.insert("Z", 26, 1);
     {
          assert(list.size() is 4);
          const MyNode* head = list.head();
          assert(head is_not nullptr);
          assert(head->name is "A");
          assert(head->score is 1);
          assert(head->prev is nullptr);
          assert(head->next is_not nullptr);

          assert(head->next->name is "Z");
          assert(head->next->score is 26);
          assert(head->next->prev is_not nullptr);
          assert(head->next->prev is head);
          assert(head->next->next is_not nullptr);

          assert(head->next->next->name is "B");
          assert(head->next->next->score is 2);
          assert(head->next->next->next is_not nullptr);
          assert(head->next->next->prev is head->next);

          assert(head->next->next->next->name is "C");
          assert(head->next->next->next->score is 3);
          assert(head->next->next->prev is_not nullptr);
          assert(head->next->next->prev is head->next);
          assert(head->next->next->next->next is nullptr);
          assert(head->next->next->next->prev is_not nullptr);
          assert(head->next->next->next->prev is head->next->next);
     }

     END_TEST
}

bool test_insert_empty() {
     MyList list = MyList();
     assert(list.size() is 0);
     assert(list.head() is nullptr);

     list.insert("Z", 26, 0);
     END_TEST
}

bool test_insert_singleton() {
     MyList list = MyList();
     list.add("A", 1);
     {
          assert(list.size() is 1);
          const MyNode* head = list.head();
          assert(head is_not nullptr);
          assert(head->next is nullptr);
          assert(head->prev is nullptr);
          assert(head->name is "A");
          assert(head->score is 1);
     }

     list.insert("Z", 26, 1);
     END_TEST
}

bool test_insert_out_of_bounds() {
     MyList list = MyList();
     list.add("A", 1);
     list.add("B", 2);
     list.add("C", 3);

     {
          assert(list.size() is 3);
          const MyNode* head = list.head();
          assert(head is_not nullptr);
          assert(head->name is "A");
          assert(head->score is 1);
          assert(head->prev is nullptr);
          assert(head->next is_not nullptr);
          assert(head->next->name is "B");
          assert(head->next->score is 2);
          assert(head->next->prev is_not nullptr);
          assert(head->next->prev is head);
          assert(head->next->next is_not nullptr);
          assert(head->next->next->name is "C");
          assert(head->next->next->score is 3);
          assert(head->next->next->next is nullptr);
          assert(head->next->next->prev is head->next);
     }

     {
          assert(list.insert("Z", 26, list.size() + 1) is false);
          assert(list.size() is 3);
          const MyNode* head = list.head();
          assert(head is_not nullptr);
          assert(head->name is "A");
          assert(head->score is 1);
          assert(head->prev is nullptr);
          assert(head->next is_not nullptr);
          assert(head->next->name is "B");
          assert(head->next->score is 2);
          assert(head->next->prev is_not nullptr);
          assert(head->next->prev is head);
          assert(head->next->next is_not nullptr);
          assert(head->next->next->name is "C");
          assert(head->next->next->score is 3);
          assert(head->next->next->next is nullptr);
          assert(head->next->next->prev is head->next);
     }
     END_TEST
}


int main() {
     unsigned pass_cnt = 0, fail_cnt = 0, skip_cnt = 0;

     test(create);

     test(add);

     test(clear_empty);
     test(clear_not_empty);

     test(remove_head);
     test(remove_tail);
     test(remove_middle);
     test(remove_empty);
     test(remove_fail);
     test(remove_singleton);

     test(insert_head);
     test(insert_tail);
     test(insert_middle);
     test(insert_empty);
     test(insert_singleton);
     test(insert_out_of_bounds);

     cout << "\n";
     cout << magenta << "summary:" << reset << "\n";
     cout << green << pass_cnt << " tests passing." << reset << "\n";
     cout << red << fail_cnt << " tests failing." << reset << "\n";
     cout << yellow << skip_cnt << " tests skipped." << reset << "\n";

     return 0;
}