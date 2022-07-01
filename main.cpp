#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <cstring>
#include <iterator>
#include <array>
#include <stdio.h>
using namespace std;
using std::array;
using std::remove;


int main(int argc, char** argv) {
    string ui = "==============================도서관리 프로그램==============================";
    string main_choice;
    string lend_num;
    string recommend_num;
    string log_num;
    string input_check_ID;
    string input_check_PW;
    string input_join_ID;
    string input_join_PW;
    string result;
    string regist_num;
    string basket[5];
    string q_basket;
    string return_book;
    string arr[5];


    while (true) {
        letusgo:                        //회원가입 후 페이지 이동을 위해 선언
        cout << ui << "\n" << endl;
        cout << "어서오세요." << endl;
        cout << "도서관리 프로그램에 오신 것을 환영합니다." << "\n" << endl;          //회원명 추가 해보기
        cout << "1. 로그인 " << endl;
        cout << "2. 회원가입 " << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "원하시는 메뉴를 선택해주세요 : " << endl;
        cin >> log_num;
        cout << ui << "\n" << endl;


        //로그인
        if (log_num == "1") {
            string check;
            int offset;
            cout << "< 로그인 >" << endl;
            cout << "ID를 입력해주세요 : " << endl;
            cin >> input_check_ID;
            cout << "pw를 입력해주세요 : " << endl;
            cin >> input_check_PW;

            ifstream member_check;
            member_check.open("check_member_info.txt");
            while (!member_check.eof()) {

                getline(member_check, check);
                // input된 id랑 pw가 한줄에 입력되어져있는지 확인(한계정당 = 한줄)

                if ((offset = check.find(input_check_ID, 0)) != string::npos &&
                    (offset = check.find(input_check_PW, 0)) != string::npos) {
                    cout << ui << "\n" << endl;
                    cout << "success login" << endl;
                    member_check.close();
                    goto main_ui;
                } else {
                    cout << "---------------------------------------------------------------------------" << endl;
                    cout << "다시 시도해주세요." << endl;
                    continue;

                }
            }
        }

            //회원가입
        else if (log_num == "2") {
            cout << "< 회원가입 >" << endl;
            cout << "ID를 입력해주세요 : " << endl;
            cin >> input_join_ID;


            ifstream member_join;
            member_join.open("check_member_info.txt");
            while (!member_join.eof()) {
                int offset;
                string check;

                getline(member_join, check);
                // 외부파일에 중복되는 데이터가 있는지 확인
                if ((offset = check.find(input_join_ID, 0)) != string::npos) {
                    cout << "사용불가능한 ID입니다." << endl;
                    cout << "다시 시도해주세요." << endl;
                    break;
                }
                    //없을 시 진행
                else {
                    cout << "사용가능한 ID입니다." << endl;
                }
                cout << "Pw를 입력해주세요 : " << endl;
                cin >> input_join_PW;
                ofstream member_join1("check_member_info.txt", std::ios_base::out | std::ios_base::app);
                member_join1.is_open();
                while (!member_join1.eof()) {
                    member_join1 << input_join_ID;
                    member_join1 << input_join_PW;
                    member_join1 << endl;

                    cout << ui << "\n" << endl;
                    cout << "회원가입이 완료되었습니다." << endl;
                    goto letusgo;
                }
            }
        } else {
            cout << "번호를 정확히 입력해주세요." << endl;
        }
    }

    main_ui:
    while (true) {
        cout << "\n" << ui << endl;
        cout << endl;
        cout << "< main >" << endl;
        cout << "1. 조회" << endl;
        cout << "2. 대여" << endl;
        cout << "3. 추천 도서" << endl;
        cout << "4. 반납" << endl;
        cout << "5. 로그인창으로 이동" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;

        cout << "원하시는 메뉴를 선택해주세요 :" << endl;
        cin >> main_choice;
        cout << endl;
        cout << ui << "\n" << endl;


        //도서조회창으로 이동
        if (main_choice == "1") {
            while (true) {
                cout << ui << "\n" << endl;
                cout << "<<검색 가능 대상>>" << "\n" << "\n";
                cout << "-도서 ( 도서 입력 )" << endl;
                cout << "-저자 ( 저자 입력 )" << endl;
                cout << "-특정도서관의 도서( 특정도서관, 도서 입력 )" << endl;
                cout << "뒤로가기를 원하신다면 < exit >를 쳐주세요." << endl;
                cout << "---------------------------------------------------" << endl;
                cout << "찾으시는 도서, 저자, 특정도서관의 도서등을 입력해주세요 : " << endl;

                string book_name;
                cin >> book_name;
                cout << book_name << endl;
                if (book_name == "exit")
                    break;

                ifstream library1;
                int offset1;
                string line1;
                library1.open("/home/hello/CLionProjects/untitled4/book_list.csv");

                while (!library1.eof()) {
                    getline(library1, line1); // 한 줄씩 읽으며 해당 문자열을 찾음
                    if ((offset1 = line1.find(book_name, 0)) != string::npos) {
                        cout << line1 << endl;
                    }
                }
                library1.close();
                cout << "---------------------------------------------------------------------------" << endl;
                cout << "도서검색이 완료되었습니다." << endl;
                cout << "뒤로가기를 원하신다면 exit를 입력해주세요.\n장바구니에 넣으실 도서의 등록번호를 입력해주세요 : " << endl;
                cin >> regist_num;
                if (regist_num == "exit")
                    break;
                ifstream library2;
                int offset2;
                string line2;
                library2.open("/home/hello/CLionProjects/untitled4/book_list.csv");
                while (!library2.eof()) {
                    getline(library2, line2); // 한 줄씩 읽으며 해당 문자열을 찾음
                    if ((offset2 = line2.find(regist_num, 0)) != string::npos)
                    {
                        int len = sizeof(basket) / sizeof(basket[0]);       //basket배열의 길이
                        if (len <= 0)
                            basket[0] = line2;
                        else
                            basket[len - 1] = line2;          //테스트후 길이 조정해라 ㄱㅊ
                    }
                }
                library2.close();
                cout << "장바구니에 추가되었습니다." << endl;
                goto main_ui;
            }
        }
            // 도서 대여창으로 이동
        else if (main_choice == "2") {
            while (true) {
                cout << "< 대여기능 >" << endl;
                cout << endl;
                cout << "1. 장바구니 목록 확인 및 대여" << endl;
                cout << "2. 대여 목록 확인" << endl;
                cout << "3. 뒤로가기" << endl;
                cout << endl;
                cout << "원하시는 메뉴를 선택해주세요 : " << endl;
                cin >> lend_num;
                cout << ui << "\n" << endl;

                if (lend_num == "1") {
                    cout << "< 장바구니 목록 확인 및 대여 >" << endl;
                    int len = sizeof(basket) / sizeof(basket[0]);
                    for (int i = 0; i < len; i++)
                        cout << basket[i] << endl;
                    cout << "\n\n\n\n" << "장바구니에 담긴 도서를 대여하시겠습니까?(y/n) :" << endl;
                    cin >> q_basket;

                    if (q_basket == "y") {
                        ofstream lend("borrow_book.txt", std::ios_base::out | std::ios_base::app);
                        lend.is_open();
                        while (!lend.eof()) {
//                            int len = sizeof(basket) / sizeof(basket[0]);
//                            lend << basket;         //이거 코드 맞는지 확인해봐라
                            for (int i = 0; i < len; i++)
                                lend << basket[i] << endl;
                            cout << "---------------------------------------------------------------------------"
                                 << endl;
                            cout << "대여가 완료되었습니다." << endl;
                            cout << ui << "\n" << endl;
                            break;
                        }
                        basket[0].clear();
                        basket[1].clear();
                        basket[2].clear();
                        basket[3].clear();
                        basket[4].clear();
                    }
                } else if (lend_num == "2") {
                    cout << "< 대여 목록 확인 >" << endl;
                    string line3;
                    ifstream file2("borrow_book.txt");
                    if (file2.is_open()) {
                        while (getline(file2, line3)) {
                            cout << line3 << endl;
                        }
                    }
                    file2.close(); // 열었던 파일을 닫는다.
                    cout << ui << "\n" << endl;
                } else if (lend_num == "3")
                    break;

                else
                    cout << "번호를 정확히 입력해주세요." << endl;
            }
        }


            //추천 도서 기능으로 이동
        else if (main_choice == "3") {
            while (true) {
                cout << "< 추천 도서 기능 >" << endl;
                cout << "순서 -> " << "연번,관리구분,등록번호,도서명,저작자,비고" << endl;

                srand(time(NULL));
                int recommend_book_num = rand() % 122969;
                string recommend_book_num1 = to_string(recommend_book_num);     //int를 string형식으로 변경
                ifstream library3;
                int offset3;
                string line4;
                library3.open("/home/hello/CLionProjects/untitled4/book_list.csv");

                while (!library3.eof()) {
                    getline(library3, line4); // 한 줄씩 읽으며 해당 문자열을 찾음
                    if ((offset3 = line4.find(recommend_book_num1, 0)) != string::npos) {
                        cout << "★ 추천 : " << line4 << endl;
                        break;
                    }

                }
                library3.close();
                cout << endl;
                cout << "나가기를 원하신다면 exit를 입력해주세요." << endl;
                cin >> recommend_num;
                if (recommend_num == "exit")
                    goto main_ui;
                else
                    cout << "번호를 정확히 입력해주세요." << endl;
            }
        } else if (main_choice == "4") {
            cout << "< 반납 >" << "\n" << endl;
            cout << "< 회원님의 도서 대여목록 >"<< endl;
            string line4;
            ifstream file3("borrow_book.txt");
            if (file3.is_open())
            {
                while (getline(file3, line4)) {
                    int i = 0;
                    cout << line4 << endl;
                    arr[i] = line4;                         //도서 대여목록을 배열로 옮겨 저장
                    i++;
                    cout << arr[i] << endl;
                }
//                file3.close();


                //특정 배열 삭제
                cout << "뒤로가기를 원하시면 exit를 입력해주세요.\n반납하고자 하는 도서의 등록번호를 입력해주세요 :" << endl;
                cin >> return_book;
                if (return_book =="exit")
                    goto main_ui;
                int len = sizeof(arr) / sizeof(arr[0]);
                for (int i =0 ; i<len ; i++)
                    if (arr[i].find(return_book) != string::npos){
                        arr[i].clear();
                    }
                    else
                        continue;
                file3.close();


                remove("borrow_book.txt");
                string line5;
                int offset4;
                ifstream library5("borrow_book.txt", std::ios_base::out | std::ios_base::app);
                library5.is_open();
                int len1 = sizeof(arr) / sizeof(arr[0]);
                for (int i=0 ; i<25 ; i++)
                {
                    library5 >> arr[i];
                }
                cout << "반납이 완료되었습니다.\n이용해주셔서 감사합니다." << endl;
                library5.close();
            }
            } else if (main_choice == "5") {
                goto letusgo;
            } else {
                cout << "번호를 정확히 입력해주세요. " << endl;
            }
        }
}

