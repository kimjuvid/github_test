#include <iostream>
#include <string>
#include <fstream>
#include <vector>


using namespace std;

int main(int argc, char** argv) {
    string ui = "==============================도서관리 프로그램==============================";
    string main_choice;        //main ui 메뉴선택시 사용될 변수
    int search_num;          //search 메뉴선택시 사용될 변수
    int lend_num;           //lend 메뉴선택시 사용될 변수
    int recommend_num;
    string log_num;
    string input_check_ID;
    string input_check_PW;
    string input_join_ID;
    string input_join_PW;
    string result;
    string regist_num;
    string basket[5];
    string q_basket;




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
                    continue;
//                    cout << ui << "\n" << endl;
//                    cout<< "\n" << "fail login" <<"\n" << endl;
//                    member_check.close();
//                    break;
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
        cout << "4. 홈으로" << endl;
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
            while (true)
            {
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
                library1.open("C:\\Users\\kimjh\\CLionProjects\\untitled8\\book_list.csv");

                while (!library1.eof())
                {
                    getline(library1, line1); // 한 줄씩 읽으며 해당 문자열을 찾음
                    if ((offset1 = line1.find(book_name, 0)) != string::npos)
                    {
                        cout << line1 << endl;
                    }
                }
                library1.close();
            cout << "도서검색이 완료되었습니다." << endl;
            cout << "장바구니에 넣으실 도서의 등록번호를 입력해주세요 :" << endl;
            cin >> regist_num;
            ifstream library2;
            int offset2;
            string line2;
            library2.open("C:\\Users\\kimjh\\CLionProjects\\untitled8\\book_list.csv");

            while (!library2.eof())
            {
                getline(library2, line2); // 한 줄씩 읽으며 해당 문자열을 찾음
                if ((offset1 = line2.find(book_name, 0)) != string::npos)
                {
                    int len = sizeof(basket) / sizeof(basket[0]);       //basket배열의 길이

                    if (len <= 0)
                        basket[0] == line2;
                    else
                        basket[len-1] = line2;          //테스트후 길이 조정
                }
            }
            library2.close();
            cout << "장바구니에 추가되었습니다." <<endl;
            goto main_ui;
            }
        }
            // 도서 대여창으로 이동
        else if (main_choice == "2")
        {
            while (true)
            {
                cout << "< 대여기능 >" << endl;
                cout << endl;
                cout << "1. 장바구니 목록 확인 및 대여" << endl;
                cout << "2. 대여 목록 확인" << endl;
                cout << "3. 뒤로가기" << endl;
                cout << endl;
                cout << "원하시는 메뉴를 선택해주세요 : " << endl;
                cin >> lend_num;
                cout << ui << "\n" << endl;

                if (lend_num == 1)
                {
                    cout << "< 장바구니 목록 확인 및 대여 >" << endl;

                    int len = sizeof(basket) / sizeof(basket[0]);
                    for (int i = 0 ; i<len ;i++)
                        cout << basket[i];
                    cout<< "장바구니에 담긴 도서들을 대여하시겠습니까?(y/n) :" << endl;
                    cin >> q_basket;
                    if (q_basket == "y")
                    {
                        ofstream lend("borrow_book.txt", std::ios_base::out | std::ios_base::app);
                        lend.is_open();
                        while (!lend.eof()) {
                            lend << basket;         //이거 코드 맞는지 확인해봐라
                            lend << endl;
                    }

                    cout << ui << "\n" << endl;

                    }
                    else if (lend_num == 2)
                    {
                        cout << "< 대여 목록 확인 >" << endl;
                        string line3;
                        ifstream file2("borrow_book.txt"); // example.txt 파일을 연다. 없으면 생성.
                        if(file2.is_open())
                        {
                            while(getline(file2, line3))
                            {
                                cout << line3 << endl;
                            }

                        }
                        file2.close(); // 열었떤 파일을 닫는다.
                        cout << ui << "\n" << endl;
                    }
                }
                else if (lend_num == 3)
                    break;

                else
                    cout << "번호를 정확히 입력해주세요." << endl;
            }
        }





            //추천 도서 기능으로 이동
        else if (main_choice == "3") {
            while (true) {
                cout << "< 추천 도서 기능 >" << endl;
                cout << endl;
                cout << "1. 뒤로가기" << endl;
                cin >> recommend_num;
                if (recommend_num == 1)
                    break;

                else {
                    cout << "번호를 정확히 입력해주세요." << endl;
                }
                cout << endl;
            }
        } else if (main_choice == "4") {
            goto letusgo;
        } else {
            cout << "번호를 정확히 입력해주세요. " << endl;
        }
    }
}
