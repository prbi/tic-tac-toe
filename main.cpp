#include <bits/stdc++.h>

using namespace std;

queue<int> v;
int calc_comp_ind(int m[3][3], int index, int count, int lst_comp_ind) {
	if (m[1][1] == -1)
		return 5;
	else if (count == 0)
		return 1;


	int a = (lst_comp_ind-1)/3, b = (lst_comp_ind-1)%3;

	int ind = lst_comp_ind;
	int res = -1;
	while (!v.empty())
	{
		res = v.front();
		v.pop();
		if(m[(res-1)/3][(res-1)%3])
			break;
		else
			res = -1;
	}
	for(int i = 0; i < 2;i++) {
	if(i==1 || ind == -1) {
		a = (index-1)/3; b = (index-1)%3;
		ind = index;
	}
        if (m[a][b] == m[(a-1+3)%3][b] && m[(a+1)%3][b] == -1) {
		if (i == 0)
			return (a+1)%3*3 + b+1;
		if (res == -1)
		res = (a+1)%3*3 + b+1;
		else
			v.push((a+1)%3*3 + b+1);
	}
	       
	if (m[a][b] == m[(a+1)%3][b] && m[(a-1+3)%3][b] == -1) {
		if (i == 0)
		return (a-1+3)%3 *3+b+1;
		if (res == -1)
			res = (a-1+3)%3 *3+b+1;
		else
			v.push((a-1+3)%3 *3+b+1);
	}

        if (m[a][b] == m[a][(b-1+3)%3] && m[a][(b+1)%3] == -1) {
		if (i == 0)
		return a*3+(b+1)%3+1;
		if (res == -1)
			res = a*3+(b+1)%3+1;
		else
			v.push(a*3+(b+1)%3+1);
	}
	
	if (m[a][b] == m[a][(b+1)%3] && m[a][(b-1+3)%3] == -1) {
		if (i == 0)
                return a*3+(b-1+3)%3+1;
		if (res == -1)
			res = a*3+(b-1+3)%3+1;
		else
			v.push(a*3+(b-1+3)%3+1);
	}

        if(ind == 1 || ind == 5 || ind == 9) {
                if (m[a][b] == m[(a+1)%3][(b+1)%3] && m[(a-1+3)%3][(b-1+3)%3] == -1) {
			if (i == 0)
		        return (a-1+3)%3*3+(b-1+3)%3+1;
			if(res == -1)
				res = (a-1+3)%3*3+(b-1+3)%3+1;
			else
				v.push((a-1+3)%3*3+(b-1+3)%3+1);
		}
		if (m[a][b] == m[(a-1+3)%3][(b-1+3)%3] && m[(a+1)%3][(b+1)%3] == -1) {
			if (i == 0)
			return (a+1)%3*3+(b+1)%3+1;
			if (res == -1)
				res = (a+1)%3*3+(b+1)%3+1;
			else
				v.push((a+1)%3*3+(b+1)%3+1);
		}
        }

        if(ind == 3 || ind == 5 || ind == 7) {
                if (m[a][b] == m[(a-1+3)%3][(b+1)%3] && m[(a+1)%3][(b-1+3)%3] == -1) {
			if (i==0)
		       return (a+1)%3*3+(b-1+3)%3+1;
			if (res == -1)
				res = (a+1)%3*3+(b-1+3)%3+1;
			else
				v.push((a+1)%3*3+(b-1+3)%3+1);
		}
		if (m[a][b] == m[(a+1)%3][(b-1+3)%3] && m[(a-1+3)%3][(b+1)%3] == -1) {
			if (i == 0)
                        return (a-1+3)%3*3+(b+1)%3+1;
			if (res == -1)
				res = (a-1+3)%3*3+(b+1)%3+1;
			else
				v.push((a-1+3)%3*3+(b+1)%3+1);
		}
        }
	}
	if (res != -1)
		return res;
	if (a-1 >= 0 && m[(a-1)%3][b] == -1)
		return (a-1+3)%3*3+b+1;
	if(m[(a+1)%3][b] == -1)
		return (a+1)*3+b+1;
	if (b-1>=0 && m[a][(b-1+3)%3] == -1)
		return a*3+(b-1+3)%3+1;
	if(m[a][(b+1)%3] == -1)
		return a*3+(b+1)%3+1;
	if (m[0][0] == -1)
		return 1;
	if (m[0][2] == -1)
		return 3;
	if (m[2][0] == -1)
		return 7;
	if (m[2][2] == -1)
		return 9;
	
	for(int i = 0;i<3;i++)
	{
		for(int j = 0;j<3;j++){
		if(m[i][j] == -1)
			return i*3+j+1;
		   }
	}
	return res;
}

bool check_winner(int  m[3][3], int input) {
	int a = (input-1)/3, b = (input-1)%3;
	if (m[a][b] == m[(a-1+3)%3][b] && m[a][b] == m[(a+1)%3][b])
		return true;
	if (m[a][b] == m[a][(b-1+3)%3] && m[a][b] == m[a][(b+1)%3])
		return true;

	if(input == 1 || input == 5 || input == 9) {
		if (m[0][0] == m[1][1] && m[1][1] == m[2][2])
			return true;
	}

	if(input == 3 || input == 5 || input == 7) {
		if (m[0][2] == m[1][1] && m[1][1] == m[2][0])
			return true;
	}
	return false;
}

void play_with_computer() {
        system("clear");
        int m[3][3];
        for(int i = 0;i<3;i++)
                for(int j = 0;j<3;j++)
                        m[i][j]=-1;
        int count = 0, player = 0;
	int comp_ind = -1;
        while(count < 9) {
                cout<<"--------------------Tic Tac Toe-------------------\n";
                for(int i = 1;i<=9;i++) {
                        int a = (i-1)/3;
                        int b = (i-1)%3;
                        if (m[a][b] == -1) {
                                cout << " ";
                        } else if (m[a][b] == 0) {
                                cout << "X";
                        } else {
                                cout << "O";
                        }
                        if (i%3 == 0) {
                                cout<<endl;
				if(i!=9)
                                cout<<"--|---|--\n";
                        } else {
                                cout<<" | ";
                        }
                }
		if (comp_ind != -1) 
			cout<<"\nComputer choose " << comp_ind << "\n" <<endl;

                string input;
                for (int i = 0; i < 3; i++) {
                cout << "Player " << player << "(";
 	 	if(player == 0)
                        cout << "X): ";
                else
                        cout << "0): ";
                cin >> input;
                if (input.size() > 1 || !isdigit(input[0]) || stoi(input) == 0) {
                        cout << "Invalid Input. ";
                } else {
			int a = (stoi(input)-1)/3;
                        int b = (stoi(input)-1)%3;
                        if(m[a][b] != -1) {
                        cout<< "Block already filled. ";
                } else {
                        m[a][b] = player;
                        break;
                }
                }
                cout << 2-i << " more changes left.\n";
                if (i == 2) {
                        cout << "Player " << (player + 1)%2 << " won. Congratulations!!!\n";
                        return;
                }
                }
                if(count >= 4) {
                        if (check_winner(m, stoi(input)) == true) {
                                cout << "Player " << player << " won. Congratulations!!!\n";
                                return;
                        }
                        if (count == 8) {
                                cout << "Match Draw!!!\n";
                                return;
                        }
                }
		comp_ind = calc_comp_ind(m, stoi(input), count, comp_ind);
		int a = (comp_ind-1)/3;
                int b = (comp_ind-1)%3;
		m[a][b] = (player+1)%2;
                if (check_winner(m, comp_ind) == true) {
			cout<<"\nComputer choose " << comp_ind << "\n" <<endl;
                        cout << "Computer won. Better luck next time\n";
			return;
                }
                count+=2;
                //system("clear");
        }
}

void play_with_friend() {
	system("clear");
	int m[3][3];
	for(int i = 0;i<3;i++)
		for(int j = 0;j<3;j++)
			m[i][j]=-1;
	int count = 0, player = 0;
	while(count < 9) {
		cout<<"--------------------Tic Tac Toe-------------------\n";
		for(int i = 1;i<=9;i++) {
			int a = (i-1)/3;
			int b = (i-1)%3;
			if (m[a][b] == -1) {
				cout << " ";
			} else if (m[a][b] == 0) {
				cout << "X";
			} else {
				cout << "O";
			}
			if (i%3 == 0) {
				cout<<endl;
				if(i!=9)
				cout<<"--|---|--\n";
			} else {
				cout<<" | ";
			}
		}
		string input;
		for (int i = 0; i < 3; i++) {
		cout << "Player " << player << "(";
		if(player == 0)
			cout << "X): ";
		else
			cout << "0): ";
		cin >> input;
		if (input.size() > 1 || !isdigit(input[0]) || stoi(input) == 0) {
			cout << "Invalid Input. ";
		} else {
			int a = (stoi(input)-1)/3;
			int b = (stoi(input)-1)%3;
			if(m[a][b] != -1) {
			cout<< "Block already filled. ";
		} else {
			m[a][b] = player;
			break;
		}
		}
		cout << 2-i << " more changes left.\n";
		if (i == 2) {
			cout << "Player " << (player + 1)%2 << " won. Congratulations!!!\n";
			return;
		}
		}
		if(count >= 4) {
			if (check_winner(m, stoi(input)) == true) {
				cout << "Player " << player << " won. Congratulations!!!\n";
				return;
			}
			if (count == 8) {
				cout << "Match Draw!!!\n";
				return;
			}
		}
		player = (player+1)%2;
		count++;
		system("clear");
	}
}

void about_us() {
	string s;
	fstream file;
	system("clear");
	file.open("about_us.txt");
	while(!file.eof()) {
		getline(file, s, '?');
		cout << s << endl;
	}
	cout << "\n\nPress any key to go back to main menu...";
	getchar();
	getchar();
	system("clear");
}

int main() {
	system("clear");
	while(1) {
	cout<<"--------------------Tic Tac Toe-------------------\n";
	cout<<" 1. Play with computer\n 2. Play with friend\n 3. About us\n 4. Exit\n Enter choice: ";
	string option;
	cin >> option;

	if (option == "1") {
		play_with_computer();
	} else if (option == "2") {
		play_with_friend();
	} else if (option == "3") {
		about_us();
	} else if (option == "4") {
		cout<<" Exiting...\n";
		exit(0);
	} else {
                cout<<"Invalid input!!! Please choose correct option.\n";
	}
	}
	return 0;
}
