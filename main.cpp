#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
// #include <conio.h>
// #include <process.h>
#include <stdio.h>
int turn = 1;
int undostart = 0;

using namespace std;

class chess
{
	int Pcheck, Bcheck, Ncheck, Qcheck, Rcheck, pcheck, bcheck, ncheck, qcheck, rcheck;
	int xx, yy; //attacking pieces in check
	int wmate, bmate;
	int wking;
	int stalemate;
	int bking;
	int wrcastle;
	int wlcastle;
	int brcastle;
	int blcastle;
	int wcastle;
	int enpassantw;
	int enpassantb;
	int bcastle;
	int win;
	int swapun;
	char undof[100], undot[100];
	int rowi[100], rowf[100], coli[100], colf[100];
	int f[2];
	char a[10][11];
	char b[10];
	char c[10];
	char undo10[10][100];
	char d[10][10];
	int aa, bb, cc, dd;
	int uaa, ubb, ucc, udd;
	int flag;
	void display();
	void assign()
	{

		if (b[0] == 'a')
			aa = 1;
		if (b[0] == 'b')
			aa = 2;
		if (b[0] == 'c')
			aa = 3;
		if (b[0] == 'd')
			aa = 4;
		if (b[0] == 'e')
			aa = 5;
		if (b[0] == 'f')
			aa = 6;
		if (b[0] == 'g')
			aa = 7;
		if (b[0] == 'h')
			aa = 8;
		uaa = aa;

		if (b[1] == '8')
			bb = 1;
		if (b[1] == '7')
			bb = 2;
		if (b[1] == '6')
			bb = 3;
		if (b[1] == '5')
			bb = 4;
		if (b[1] == '4')
			bb = 5;
		if (b[1] == '3')
			bb = 6;
		if (b[1] == '2')
			bb = 7;
		if (b[1] == '1')
			bb = 8;
		ubb = bb;

		if (c[0] == 'a')
			cc = 1;
		if (c[0] == 'b')
			cc = 2;
		if (c[0] == 'c')
			cc = 3;
		if (c[0] == 'd')
			cc = 4;
		if (c[0] == 'e')
			cc = 5;
		if (c[0] == 'f')
			cc = 6;
		if (c[0] == 'g')
			cc = 7;
		if (c[0] == 'h')
			cc = 8;
		ucc = cc;

		if (c[1] == '8')
			dd = 1;
		if (c[1] == '7')
			dd = 2;
		if (c[1] == '6')
			dd = 3;
		if (c[1] == '5')
			dd = 4;
		if (c[1] == '4')
			dd = 5;
		if (c[1] == '3')
			dd = 6;
		if (c[1] == '2')
			dd = 7;
		if (c[1] == '1')
			dd = 8;
		udd = dd;
	}
	void assign(char b[])
	{

		if (b[0] == 'a')
			aa = 1;
		if (b[0] == 'b')
			aa = 2;
		if (b[0] == 'c')
			aa = 3;
		if (b[0] == 'd')
			aa = 4;
		if (b[0] == 'e')
			aa = 5;
		if (b[0] == 'f')
			aa = 6;
		if (b[0] == 'g')
			aa = 7;
		if (b[0] == 'h')
			aa = 8;
		uaa = aa;

		if (b[1] == '8')
			bb = 1;
		if (b[1] == '7')
			bb = 2;
		if (b[1] == '6')
			bb = 3;
		if (b[1] == '5')
			bb = 4;
		if (b[1] == '4')
			bb = 5;
		if (b[1] == '3')
			bb = 6;
		if (b[1] == '2')
			bb = 7;
		if (b[1] == '1')
			bb = 8;
		ubb = bb;
	}
	void input()
	{
		int ch = 0;
		int h = 0;
		int l1flag = 0;
		int l2flag = 0;
		int u = 0;

		if (turn % 2 == 0)
		{

			h = whitestalemate();
			xx = 0;
			yy = 0;
			Pcheck = 0;
			Bcheck = 0;
			Ncheck = 0;
			Qcheck = 0;
			Rcheck = 0;
			pcheck = 0;
			bcheck = 0;
			ncheck = 0;
			qcheck = 0;
			rcheck = 0;
			if (h == 1)
			{
				cout << "It is a stalemate, game is a draw\n";
				stalemate = 1;
				complete();
			}
		}
		if (turn % 2 == 1)
		{
			h = blackstalemate();
			xx = 0;
			yy = 0;
			Pcheck = 0;
			Bcheck = 0;
			Ncheck = 0;
			Qcheck = 0;
			Rcheck = 0;
			pcheck = 0;
			bcheck = 0;
			ncheck = 0;
			qcheck = 0;
			rcheck = 0;
			if (h == 1)
			{
				cout << "It is a stalemate, game is a draw\n";
				stalemate = 1;
				complete();
			}
		}
		while (1)
		{

			if (turn > 2)
				cout << "Enter the position of the piece you wish to move in letter-number notation using lowercase (eg e4) OR enter 1 if you want to undo\n";
			else
				cout << "Enter the position of the piece you wish to move in letter-number notation using lowercase (eg e4)\n";
			cin.getline(b, 10);
			if (b[0] == 49u && undostart > 0)
				undomove();

			if (b[1] >= 49 && b[1] <= 56 && b[0] >= 'a' && b[0] <= 'h')
			{
				assign(b);
				if (turn % 2 == 0 && strlen(b) == 2)
				{
					if (a[bb][aa] >= 'A' && a[bb][aa] <= 'Z')
					{
						l1flag = 1;
						break;
					}
				}
				if (turn % 2 == 1 && strlen(b) == 2)
				{
					if (a[bb][aa] >= 'a' && a[bb][aa] <= 'z')
					{
						l1flag = 1;
						break;
					}
				}
			}
			else
				cout << "Enter a valid position (letters a-h,numbers 1-8)";
		}
		while (1)
		{
			cout << "Enter the position of the piece you wish to move TO in letter-number notation using lowercase (eg f6) \n";
			cin.getline(c, 10);
			if ((c[0] >= 'a' && c[0] <= 'h' && c[1] >= 49 && c[1] <= 56) && strlen(c) == 2)
			{
				l2flag = 1;
				break;
			}
			else
				cout << "Enter a valid position (letters a-h,numbers 1-8)";
		}
		if (l1flag == 1 && l2flag == 1)
			assign();
		error();
	}

	void error()
	{

		while (1)
		{
			int wflag = 0;
			int bflag = 0;
			int wmove = 0;
			int bmove = 0;
			if (turn % 2 == 0)
				wmove = 1;
			else
				bmove = 1;
			if (wmove == 1)
			{
				if (((a[dd][cc] > 'a' && a[dd][cc] < 'z') || a[dd][cc] == '.') && (a[bb][aa] > 'A' && a[bb][aa] < 'Z'))
					wflag = 1;
			}

			if (bmove == 1)
			{
				if (((a[dd][cc] > 'A' && a[dd][cc] < 'Z') || a[dd][cc] == '.') && (a[bb][aa] > 'a' && a[bb][aa] < 'z'))
					bflag = 1;
			}

			if (wflag == 1 || bflag == 1)
			{

				move();
				break;
			}
			else
			{
				cout << "You have entered an illegal move, please enter a legal one\n";
				input();
			}
		}
	}

	int movepawn(int bb, int aa, int dd, int cc)
	{

		if (dd >= 9 || dd <= 0 || cc >= 9 || cc <= 0)
			return 0;
		if ((f[0] + 2 <= turn) && f[0] != 0)
		{
			enpassantw = 0;
		}
		if ((f[1] + 2 <= turn) && f[1] != 0)
		{
			enpassantb = 0;
		}
		flag = 0;
		if (a[bb][aa] == 'P')
		{
			int ya = 0;
			if (bb == 7 && a[dd][cc] == '.' && aa == cc && dd == bb - 2) //two steps front
			{
				flag = 2;
				enpassantw = 1;
				f[0] = turn;
			}
			if (bb == 7 && a[dd][cc] == '.' && aa == cc && dd == bb - 1) //one step front
				flag = 2;
			if (bb != 7 && a[dd][cc] == '.' && aa == cc && dd == bb - 1) //one step front
				flag = 2;
			if (bb != 7 && a[dd][cc] != '.' && aa == cc - 1 && dd == bb - 1) //right attack
				flag = 2;
			if (bb != 7 && a[dd][cc] != '.' && aa == cc + 1 && dd == bb - 1) //left attack
				flag = 2;
			if (((bb == 4 && a[dd][cc] == '.' && aa == cc - 1 && dd == bb - 1) && (a[bb][aa + 1] == 'p')) && enpassantb == 1) //right enpassant
			{
				a[bb][aa + 1] = '.';
				flag = 2;
			}
			if (((bb == 4 && a[dd][cc] == '.' && aa == cc + 1 && dd == bb - 1) && (a[bb][aa - 1] == 'p')) && enpassantb == 1) //left enpassant
			{
				a[bb][aa - 1] = '.';
				flag = 2;
			}
			ya = b[1];

			if (b[1] == 55 && turn % 2 == 0 && (c[1] == 56))
			{
				swap();
				promotion();
			}
		}
		if (a[bb][aa] == 'p')
		{

			if (bb == 2 && a[dd][cc] == '.' && aa == cc && dd == bb + 2) //two steps front

			{
				flag = 2;
				enpassantb = 1;
				f[1] = turn;
			}
			if (bb == 2 && a[dd][cc] == '.' && aa == cc && dd == bb + 1) //one step front
				flag = 2;
			if (bb != 2 && a[dd][cc] == '.' && aa == cc && dd == bb + 1) //one step front
				flag = 2;
			if (bb != 2 && a[dd][cc] != '.' && aa == cc - 1 && dd == bb + 1) //right attack
				flag = 2;
			if (bb != 2 && a[dd][cc] != '.' && aa == cc + 1 && dd == bb + 1) //left attack
				flag = 2;
			if (((bb == 5 && a[dd][cc] == '.' && aa == cc - 1 && dd == bb + 1) && (a[bb][aa + 1] == 'P')) && enpassantw == 1) //right enpassant
			{
				a[bb][aa + 1] = '.';
				flag = 2;
			}
			if (((bb == 5 && a[dd][cc] == '.' && aa == cc + 1 && dd == bb + 1) && (a[bb][aa - 1] == 'P')) && enpassantw == 1) //left enpassant
			{
				a[bb][aa - 1] = '.';
				flag = 2;
			}
			if (b[1] == 50 && turn % 2 == 1 && c[1] == 49)
			{
				swap();
				promotion();
			}
		}

		if (flag == 2)
			return 1;
		else
			return 0;
	}
	int movebishop(int bb, int aa, int dd, int cc)
	{
		if (dd >= 9 || dd <= 0 || cc >= 9 || cc <= 0)
			return 0;
		if (a[bb][aa] == 'B' || a[bb][aa] == 'b')
		{

			flag = 0;
			if (a[bb][aa] == 'B' || a[bb][aa] == 'b')
			{
				int x = 0;
				int ap = 0;
				if (dd - bb == cc - aa || dd - bb == -(cc - aa))
					flag = 1;
				if (flag == 1)
				{
					if (dd - bb > 0 && cc - aa > 0) //top left to bottom right
					{
						x = dd - bb;
						for (int i = 1; i <= x; i++)
						{
							if (a[bb + i][aa + i] == '.')
								ap++;
						}
						if (a[bb + x][aa + x] != '.')
							ap++;
					}
					if (dd - bb > 0 && cc - aa < 0) //top right to bottom left
					{
						x = dd - bb;
						for (int i = 1; i <= x; i++)
						{
							if (a[bb + i][aa - i] == '.')
								ap++;
						}

						if (a[bb + x][aa - x] != '.')
							ap++;
					}
					if (dd - bb < 0 && cc - aa > 0) //bottom left to top right
					{
						x = cc - aa;
						for (int i = 1; i <= x; i++)
						{
							if (a[bb - i][aa + i] == '.')
								ap++;
						}

						if (a[bb - x][aa + x] != '.')
							ap++;
					}
					if (dd - bb < 0 && cc - aa < 0) //bottom right to top left
					{
						x = -(cc - aa);
						for (int i = 1; i <= x; i++)
						{
							if (a[bb - i][aa - i] == '.')
								ap++;
						}

						if (a[bb - x][aa - x] != '.')
							ap++;
					}
					if ((ap > 0 && x > 0) && (ap == x) || x == 1)
						flag = 2;
				}
			}
			if (flag == 2)
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}
	int moveknight(int bb, int aa, int dd, int cc)
	{
		if (dd >= 9 || dd <= 0 || cc >= 9 || cc <= 0)
			return 0;

		flag = 0;
		if (a[bb][aa] == 'n' || a[bb][aa] == 'N')
		{
			if (((dd - bb == 2) && (cc - aa == 1)) || ((dd - bb == -2) && (cc - aa == 1)) || ((dd - bb == 2) && (cc - aa == -1)) || ((dd - bb == -2) && (cc - aa == -1)) || ((dd - bb == 1) && (cc - aa == 2)) || ((dd - bb == 1) && (cc - aa == -2)) || ((dd - bb == -1) && (cc - aa == 2)) || ((dd - bb == -1) && (cc - aa == -2)))
			{

				flag = 2;
			}
		}
		if (flag == 2)
			return 1;
		else
			return 0;
	}
	int moverook(int bb, int aa, int dd, int cc)
	{
		if (dd >= 9 || dd <= 0 || cc >= 9 || cc <= 0)
			return 0;
		if (a[bb][aa] == 'R' || a[bb][aa] == 'r')
		{

			flag = 0;
			int x = 0;
			int ap = 0;
			if ((bb == dd && aa != cc) || (aa == cc && bb != dd))
				flag = 1;
			if (flag == 1)
			{
				if (bb == dd && aa != cc) //Horizontal movement
				{

					if (cc > aa) //left to right
					{
						x = cc - aa;
						for (int i = 1; i <= x; i++)
						{
							if (a[bb][aa + i] == '.')
								ap++;
						}

						if (a[bb][aa + x] != '.')
							ap++;
					}
					if (cc < aa) //right to left
					{
						x = aa - cc;

						for (int i = 1; i <= x; i++)
						{
							if (a[bb][aa - i] == '.')
								ap++;
						}
						if (a[bb][aa - x] != '.')
							ap++;
					}
				}

				if (aa == cc && bb != dd) //Vertical movement
				{
					if (bb > dd) //bottom to top
					{
						x = bb - dd;
						for (int i = 1; i <= x; i++)
						{
							if (a[bb - i][aa] == '.')
								ap++;
						}
						if (a[bb - x][aa] != '.')
							ap++;
					}
					if (dd > bb) //top to bottom
					{

						x = dd - bb;
						for (int i = 1; i <= x; i++)
						{
							if (a[bb + i][aa] == '.')
								ap++;
						}
						if (a[bb + x][aa] != '.')
							ap++;
					}
				}
			}
			if ((ap > 0 && x > 0) && (ap == x) || x == 1)
			{

				flag = 2;
			}
			if (flag == 2)
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}

	int movequeen(int bb, int aa, int dd, int cc)
	{
		if (dd >= 9 || dd <= 0 || cc >= 9 || cc <= 0)
			return 0;
		if (a[bb][aa] == 'Q' || a[bb][aa] == 'q')
		{

			flag = 0;
			int x = 0;
			int ap = 0;
			if (dd - bb == cc - aa || dd - bb == -(cc - aa) || bb == dd && aa != cc || aa == cc && bb != dd)
				flag = 1;

			if (flag == 1)
			{

				if (dd - bb > 0 && cc - aa > 0) //top left to bottom right
				{
					x = dd - bb;
					for (int i = 1; i <= x; i++)
					{
						if (a[bb + i][aa + i] == '.')
							ap++;
					}
					if (a[bb + x][aa + x] != '.')
						ap++;
				}

				if (dd - bb > 0 && cc - aa < 0) //top right to bottom left
				{
					x = dd - bb;
					for (int i = 1; i <= x; i++)
					{
						if (a[bb + i][aa - i] == '.')
							ap++;
					}
					if (a[bb + x][aa - x] != '.')
						ap++;
				}

				if (dd - bb < 0 && cc - aa > 0) //bottom left to top right
				{
					x = cc - aa;
					for (int i = 1; i <= x; i++)
					{
						if (a[bb - i][aa + i] == '.')
							ap++;
					}
					if (a[bb - x][aa + x] != '.')
						ap++;
				}
				if (dd - bb < 0 && cc - aa < 0) //bottom right to top left
				{
					x = -(cc - aa);
					for (int i = 1; i <= x; i++)
					{
						if (a[bb - i][aa - i] == '.')
							ap++;
					}
					if (a[bb - x][aa - x] != '.')
						ap++;
				}
				if (bb == dd && aa != cc) //Horizontal movement
				{

					if (cc > aa) //left to right
					{
						x = cc - aa;
						for (int i = 1; i <= x; i++)
						{
							if (a[bb][aa + i] == '.')
								ap++;
						}
						if (a[bb][aa + x] != '.')
							ap++;
					}
					if (cc < aa) //right to left
					{

						x = aa - cc;
						for (int i = 1; i <= x; i++)
						{
							if (a[bb][aa - i] == '.')
								ap++;
						}
						if (a[bb][aa - x] != '.')
							ap++;
					}
				}
				if (aa == cc && bb != dd) //Vertical movement
				{

					if (bb > dd) //bottom to top
					{
						x = bb - dd;
						for (int i = 1; i <= x; i++)
						{
							if (a[bb - i][aa] == '.')
								ap++;
						}
						if (a[bb - x][aa] != '.')
							ap++;
					}
					if (dd > bb) //top to bottom
					{
						x = dd - bb;
						for (int i = 1; i <= x; i++)
						{
							if (a[bb + i][aa] == '.')
								ap++;
						}
						if (a[bb + x][aa] != '.')
							ap++;
					}
				}
			}

			if ((ap > 0 && x > 0) && (ap == x) || x == 1)
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}
	int moveking(int bb, int aa, int dd, int cc)
	{
		int q = 0;
		if (dd >= 9 || dd <= 0 || cc >= 9 || cc <= 0)
			return 0;
		int p = 0;
		flag = 0;
		if (a[bb][aa] == 'K' || a[bb][aa] == 'k')
		{

			if ((dd == bb + 1 && cc == aa + 1) || (dd == bb + 1 && cc == aa) || (dd == bb + 1 && cc == aa - 1) || (dd == bb && cc == aa - 1) || (dd == bb && cc == aa + 1) || (dd == bb - 1 && cc == aa - 1) || (dd == bb - 1 && cc == aa) || (dd == bb - 1 && cc == aa + 1))
			{

				flag = 2;
			}
			if (bb == dd && aa == cc + 2)
			{

				if (a[bb][aa] == 'K')
				{
					q = whitecheck(8, 5);
					reassign();
					if (q == 1)
					{
						cout << "Cant castle during check\n";
						return 0;
					}
					if (wking == 0 && wlcastle == 0)
						p = castle();
					if (p == 1)
					{
						wcastle = 1;
						flag = 2;
					}
					else
					{
						cout << "Illegal move, Castling can't take place if king or rook have previously moved, King can't pass through a check in castling, enter a correct move\n";
						input();
					}
				}
				if (a[bb][aa] == 'k')
				{
					q = blackcheck(1, 5);
					reassign();
					if (q == 1)
					{
						cout << "Cant castle during check\n";
						return 0;
					}

					if (bking == 0 && blcastle == 0)
						p = castle();
					if (p == 1)
					{
						bcastle = 1;
						flag = 2;
					}
					else
					{
						cout << "Illegal move, Castling can't take place if king or rook have previously moved, King can't pass through a check in castling, enter a correct move\n";
						input();
					}
				}
			}
			if (bb == dd && aa == cc - 2)
			{

				if (a[bb][aa] == 'K')
				{
					q = whitecheck(8, 5);
					reassign();
					if (q == 1)
					{
						cout << "Cant castle during check\n";
						return 0;
					}
					if (wking == 0 && wrcastle == 0)
						p = castle();
					if (p == 1)
					{
						wcastle = 1;
						flag = 2;
					}
					else
					{
						cout << "Illegal move, Castling can't take place if king or rook have previously moved, King can't pass through a check in castling, enter a correct move\n";
						input();
					}
				}
				if (a[bb][aa] == 'k')
				{
					q = blackcheck(1, 5);
					reassign();
					if (q == 1)
					{
						cout << "Cant castle during check\n";
						return 0;
					}

					if (bking == 0 && brcastle == 0)
					{

						p = castle();
					}
					if (p == 1)
					{

						bcastle = 1;
						flag = 2;
					}
					else
					{
						cout << "Illegal move, Castling can't take place if king or rook have previously moved, King can't pass through a check in castling, enter a correct move\n";
						input();
					}
				}
			}
		}
		if (flag == 2)
			return 1;
		else
			return 0;
	}
	void move()
	{

		while (1)
		{
			int c = 0;
			int b = 0;
			int a = 0;
			a = movepawn(bb, aa, dd, cc);
			if (a == 1)
			{
				b = 1;
				c = swap();
				if (c == 1)
					complete();
				break;
			}
			a = movebishop(bb, aa, dd, cc);
			if (a == 1)
			{
				b = 1;
				c = swap();
				if (c == 1)
					complete();
				break;
			}
			a = moveknight(bb, aa, dd, cc);
			if (a == 1)
			{
				b = 1;
				c = swap();
				if (c == 1)
					complete();
				break;
			}
			a = moverook(bb, aa, dd, cc);
			if (a == 1)
			{
				b = 1;
				c = swap();
				if (c == 1)
				{

					if (bb == 1 && aa == 1)
						blcastle = 1;
					if (bb == 1 && aa == 8)
						brcastle = 1;
					if (bb == 8 && aa == 1)
						wlcastle = 1;
					if (bb == 8 && aa == 8)
						wrcastle = 1;
					complete();
				}
				break;
			}
			a = movequeen(bb, aa, dd, cc);
			if (a == 1)
			{
				b = 1;
				c = swap();
				if (c == 1)
					complete();
				break;
			}
			a = moveking(bb, aa, dd, cc);
			if (a == 1)
			{
				b = 1;
				c = swap();
				if (c == 1)
				{
					if (chess::a[chess::dd][chess::cc] == 'K')
						wking++;
					if (chess::a[chess::dd][chess::cc] == 'k')
						bking++;
					complete();
				}
				break;
			}
			if (b == 0)
			{
				cout << "Illegal move, enter a correct move\n";
				input();
				break;
			}
		}
	}

	void promotion()
	{
		char ch;
		while (1)
		{
			cout << "Enter 'K' for Knight or 'Q' for queen\n";
			cin >> ch;
			if (ch == 'K' || ch == 'k' || ch == 'q' || ch == 'Q')
				break;
			else
				cout << "Enter correct choice\n";
		}
		if (a[ubb - 1][uaa] == 'P' || a[ubb - 1][uaa + 1] == 'P' || a[ubb - 1][uaa - 1] == 'P')
		{

			if (dd == 1)
			{
				a[ubb][uaa] = '.';
				if (ch == 'Q' || ch == 'q')
					a[chess::dd][chess::cc] = 'Q';
				if (ch == 'K' || ch == 'k')
					a[chess::dd][chess::cc] = 'N';
				complete();
			}
		}
		if (a[ubb + 1][uaa] == 'p' || a[ubb + 1][uaa + 1] == 'p' || a[ubb + 1][uaa - 1] == 'p')
		{
			if (dd == 8)
			{
				a[ubb][uaa] = '.';

				if (ch == 'Q' || ch == 'q')
					a[chess::dd][chess::cc] = 'q';
				if (ch == 'K' || ch == 'k')
					a[chess::dd][chess::cc] = 'n';
				complete();
			}
		}
	}
	int castle()
	{
		cout << "***Entered castle***\n";
		int v = 0;
		int u = 0;
		if (bb == 8 && aa == 5)
		{

			v = 0;
			u = 0;
			if (dd == 8 && cc == 3)
			{
				if (a[8][1] != 'R')
				{
					cout << "NOT ROOK\n";
					return 0;
				}
				if (a[8][2] == '.')
					v++;
				if (a[8][3] == '.')
					v++;
				if (a[8][4] == '.')
					v++;

				u = whitecheck(8, 4);
				reassign();
				if (v == 3 && u == 0)
				{

					a[8][4] = 'R';
					a[8][1] = '.';
					return 1;
				}
			}
			v = 0;
			u = 0;
			if (dd == 8 && cc == 7)
			{
				if (a[8][8] != 'R')
				{
					cout << "NOT ROOK\n";
					return 0;
				}
				if (a[8][6] == '.')
					v++;
				if (a[8][7] == '.')
					v++;
				cout << "******* " << v;
				u = whitecheck(8, 6);
				reassign();
				if (v == 2 && u == 0)
				{

					a[8][6] = 'R';
					a[8][8] = '.';
					return 1;
				}
			}
		}
		if (bb == 1 && aa == 5)
		{
			v = 0;
			u = 0;
			if (dd == 1 && cc == 3)
			{

				if (a[1][1] != 'r')
					return 0;

				if (a[1][2] == '.')
					v++;
				if (a[1][3] == '.')
					v++;
				if (a[1][4] == '.')
					v++;
				u = blackcheck(1, 4);
				reassign();
				if (v == 3 && u == 0)
				{
					a[1][4] = 'r';
					a[1][1] = '.';
					return 1;
				}
			}
			v = 0;
			u = 0;
			if (dd == 1 && cc == 7)
			{

				if (a[1][8] != 'r')
					return 0;

				if (a[1][6] == '.')
					v++;
				if (a[1][7] == '.')
					v++;

				u = blackcheck(1, 6);
				reassign();

				if (v == 2 && u == 0)
				{

					a[1][6] = 'r';
					a[1][8] = '.';
					return 1;
				}
			}
		}
		return 0;
	}

	void undocopy()
	{
		rowi[undostart] = bb;
		coli[undostart] = aa;
		rowf[undostart] = dd;
		colf[undostart] = cc;
		undof[undostart] = a[bb][aa];
		undot[undostart] = a[dd][cc];
		undostart++;
	}
	void undomove()
	{
		if (undof[undostart - 1] == 'K')
		{
			wking--;
		}
		if (undof[undostart - 1] == 'k')
		{
			bking--;
		}

		if ((undof[undostart - 1] == 'K') && (coli[undostart - 1] + 2 == colf[undostart - 1]))
		{
			wrcastle = 0;
			a[8][8] = 'R';
			a[8][6] = '.';
		}
		if ((undof[undostart - 1] == 'K') && (coli[undostart - 1] - 2 == colf[undostart - 1]))
		{
			wlcastle = 0;
			a[8][1] = 'R';
			a[8][6] = '.';
		}
		if ((undof[undostart - 1] == 'k') && (coli[undostart - 1] + 2 == colf[undostart - 1]))
		{
			brcastle = 0;
			a[1][8] = 'r';
			a[1][6] = '.';
		}
		if ((undof[undostart - 1] == 'k') && (coli[undostart - 1] - 2 == colf[undostart - 1]))
		{
			blcastle = 0;
			a[1][1] = 'r';
			a[1][6] = '.';
		}
		a[rowi[undostart - 1]][coli[undostart - 1]] = undof[undostart - 1];
		a[rowf[undostart - 1]][colf[undostart - 1]] = undot[undostart - 1];
		swapun = 1;
		turn -= 2;
		undostart--;
		complete();
	}

	void checkpremove()
	{

		int a, b;
		a = 0;
		b = 0;
		if (turn % 2 == 0)
		{

			a = whitecheck();
			reassign();
			if (a == 1)
			{
				undostart--;
				cout << "White  player is in check, please enter a correct move\n";

				undo();
			}
		}
		if (turn % 2 == 1)
		{

			b = blackcheck();
			reassign();
			if (b == 1)
			{
				undostart--;
				cout << "Black player is in check, please enter a correct move\n";
				undo();
			}
		}
	}
	void checkpostmove()
	{

		wmate = 0;
		bmate = 0;
		int a, b;
		a = 0;
		b = 0;

		if (turn % 2 == 0)
		{
			a = whitecheck();
			if (a == 1)
			{
				wmate = whitecheckmate();
				cout << "White player is in check\n";
			}
		}
		if (turn % 2 == 1)
		{

			b = blackcheck();
			if (b == 1)
			{
				bmate = blackcheckmate();
				cout << "Black player is in check\n";
			}
		}
	}

	void undo()
	{

		cout << "You have entered an illegal move, please re-enter\n";

		a[bb][aa] = a[dd][cc];
		a[dd][cc] = '.';

		input();
	}
	int swap()
	{
		undocopy();
		a[dd][cc] = a[bb][aa];
		a[bb][aa] = '.';

		checkpremove();
		return 1;
	}
	int wswap(int bb, int aa, int dd, int cc) //for white stalemate
	{
		cout<<"WSWAP\n";
		int h = 0;
		a[dd][cc] = a[bb][aa];
		a[bb][aa] = '.';

		h = whitecheck();
		xx = 0;
		yy = 0;
		Pcheck = 0;
		Bcheck = 0;
		Ncheck = 0;
		Qcheck = 0;
		Rcheck = 0;
		pcheck = 0;
		bcheck = 0;
		ncheck = 0;
		qcheck = 0;
		rcheck = 0;
		if (h == 1)
			return 1;
		else
			return 0;
	}

	int bswap(int bb, int aa, int dd, int cc) //for black stalemate
	{
		cout<<"BSWAP\n";
		int h = 0;
		a[dd][cc] = a[bb][aa];
		a[bb][aa] = '.';
		h = blackcheck();
		reassign();
		if (h == 1)
			return 1;
		else
			return 0;
	}
	void staleundo(int bb, int aa, int dd, int cc) //for undo during stalemate checking
	{
		a[bb][aa] = a[dd][cc];
		a[dd][cc] = '.';
	}

	int whitecheck()
	{

		int flag = 0;
		int g, h;
		g = 0;
		h = 0;
		int blackflag = 0;
		for (int i = 1; i < 9; i++)
		{
			for (int j = 1; j < 9; j++)
			{
				if (a[i][j] == 'K')
				{
					g = i;
					h = j;
				}
			}
		}
		for (int m = 1; m < 9; m++)
		{
			for (int n = 1; n < 9; n++)
			{
				if (a[m][n] == 'p')
				{
					if ((m == g - 1 && n == h + 1) || (m == g - 1 && n == h - 1))
					{
						flag = 2;
						if (flag == 2)
						{
							xx = m;
							yy = n;
							blackflag = 1;
							pcheck = 1;
						}
					}
				}
				if (a[m][n] == 'b')
				{
					int a = 0;
					int kky = 0;
					int x = 0;
					int ap = 0;
					a = movebishop(m, n, g, h);

					if (a == 1)
					{
						xx = m;
						yy = n;
						blackflag = 1;
						bcheck = 1;
					}
				}
				if (a[m][n] == 'n')
				{
					if ((g - m == 1 || g - m == -1 || g - m == 2 || g - m == -2) && (h - n == 1 || h - n == -1 || h - n == 2 || h - n == -2))

					{
						xx = m;
						yy = n;
						blackflag = 1;
						ncheck = 1;
					}
				}
				if (a[m][n] == 'r')
				{
					int a = 0;
					int kky = 0;
					int x = 0;
					int ap = 0;
					a = moverook(m, n, g, h);

					if (a == 1)
					{
						xx = m;
						yy = n;
						blackflag = 1;
						rcheck = 1;
					}
				}
				if (a[m][n] == 'q')
				{
					int a = 0;
					int kky = 0;
					int x = 0;
					int ap = 0;
					a = movequeen(m, n, g, h);

					if (a == 1)
					{
						xx = m;
						yy = n;
						blackflag = 1;
						qcheck = 1;
					}
				}
				if (a[m][n] == 'k')
				{
					if ((g == m + 1 && h == n + 1) || (g == m + 1 && h == n) || (g == m + 1 && h == n - 1) || (g == m && h == n - 1) || (g == m && h == n + 1) || (g == m - 1 && h == n - 1) || (g == m - 1 && h == n) || (g == m - 1 && h == n + 1))
					{

						blackflag = 1;
					}
				}
			}
		}
		if (blackflag == 1)
		{
			return 1;
		}
		else
			return 0;
	}
	int whitecheck(int g, int h)
	{

		int flag = 0;

		int blackflag = 0;
		for (int m = 1; m < 9; m++)
		{
			for (int n = 1; n < 9; n++)
			{
				if (a[m][n] == 'p')
				{
					if ((m == g - 1 && n == h + 1) || (m == g - 1 && n == h - 1))
					{
						flag = 2;
						if (flag == 2)
						{
							xx = m;
							yy = n;
							blackflag = 1;
							pcheck = 1;
						}
					}
				}
				if (a[m][n] == 'b')
				{
					int a = 0;
					int kky = 0;
					int x = 0;
					int ap = 0;
					a = movebishop(m, n, g, h);

					if (a == 1)
					{
						xx = m;
						yy = n;
						blackflag = 1;
						bcheck = 1;
					}
				}
				if (a[m][n] == 'n')
				{
					if ((g - m == 1 || g - m == -1 || g - m == 2 || g - m == -2) && (h - n == 1 || h - n == -1 || h - n == 2 || h - n == -2))

					{
						xx = m;
						yy = n;
						blackflag = 1;
						ncheck = 1;
					}
				}
				if (a[m][n] == 'r')
				{
					int a = 0;
					int kky = 0;
					int x = 0;
					int ap = 0;
					a = moverook(m, n, g, h);

					if (a == 1)
					{
						xx = m;
						yy = n;
						blackflag = 1;
						rcheck = 1;
					}
				}
				if (a[m][n] == 'q')
				{
					int a = 0;
					int kky = 0;
					int x = 0;
					int ap = 0;
					a = movequeen(m, n, g, h);

					if (a == 1)
					{
						xx = m;
						yy = n;
						blackflag = 1;
						qcheck = 1;
					}
				}
				if (a[m][n] == 'k')
				{
					if ((g == m + 1 && h == n + 1) || (g == m + 1 && h == n) || (g == m + 1 && h == n - 1) || (g == m && h == n - 1) || (g == m && h == n + 1) || (g == m - 1 && h == n - 1) || (g == m - 1 && h == n) || (g == m - 1 && h == n + 1))
					{

						blackflag = 1;
					}
				}
			}
		}
		if (blackflag == 1)
		{
			return 1;
		}
		else
			return 0;
	}
	int blackcheck()
	{

		int flag = 0;
		int g, h;
		g = 0;
		h = 0;
		int blackflag = 0;
		for (int i = 1; i < 9; i++)
		{
			for (int j = 1; j < 9; j++)
			{
				if (a[i][j] == 'k')
				{
					g = i;
					h = j;
				}
			}
		}
		for (int m = 1; m < 9; m++)
		{
			for (int n = 1; n < 9; n++)
			{
				if (a[m][n] == 'P')
				{
					if ((m == g + 1 && n == h - 1) || (m == g + 1 && n == h + 1))
					{
						flag = 2;
						if (flag == 2)
						{

							xx = m;
							yy = n;
							blackflag = 1;
							Pcheck = 1;
						}
					}
				}
				if (a[m][n] == 'B')
				{
					int a = 0;
					int kky = 0;
					int x = 0;
					int ap = 0;
					a = movebishop(m, n, g, h);

					if (a == 1)
					{

						xx = m;
						yy = n;
						blackflag = 1;
						Bcheck = 1;
					}
				}
				if (a[m][n] == 'N')
				{
					if ((g - m == 1 || g - m == -1 || g - m == 2 || g - m == -2) && (h - n == 1 || h - n == -1 || h - n == 2 || h - n == -2))

					{

						xx = m;
						yy = n;
						blackflag = 1;
						Ncheck = 1;
					}
				}
				if (a[m][n] == 'R')
				{
					int a = 0;
					int kky = 0;
					int x = 0;
					int ap = 0;
					a = moverook(m, n, g, h);

					if (a == 1)
					{

						xx = m;
						yy = n;
						blackflag = 1;
						Rcheck = 1;
					}
				}
				if (a[m][n] == 'Q')
				{
					int a = 0;
					int kky = 0;
					int x = 0;
					int ap = 0;
					a = movequeen(m, n, g, h);

					if (a == 1)
					{

						xx = m;
						yy = n;
						blackflag = 1;
						Qcheck = 1;
					}
				}
				if (a[m][n] == 'K')
				{
					if ((g == m + 1 && h == n + 1) || (g == m + 1 && h == n) || (g == m + 1 && h == n - 1) || (g == m && h == n - 1) || (g == m && h == n + 1) || (g == m - 1 && h == n - 1) || (g == m - 1 && h == n) || (g == m - 1 && h == n + 1))
					{

						blackflag = 1;
					}
				}
			}
		}
		if (blackflag == 1)
		{
			return 1;
		}
		else
			return 0;
	}

	int blackcheck(int g, int h)
	{
		int flag = 0;
		int blackflag = 0;

		for (int m = 1; m < 9; m++)
		{
			for (int n = 1; n < 9; n++)
			{
				if (a[m][n] == 'P')
				{
					if ((m == g + 1 && n == h - 1) || (m == g + 1 && n == h + 1))
					{
						flag = 2;
						if (flag == 2)
						{

							xx = m;
							yy = n;
							blackflag = 1;
							Pcheck = 1;
						}
					}
				}
				if (a[m][n] == 'B')
				{
					int a = 0;
					int kky = 0;
					int x = 0;
					int ap = 0;
					a = movebishop(m, n, g, h);

					if (a == 1)
					{

						xx = m;
						yy = n;
						blackflag = 1;
						Bcheck = 1;
					}
				}
				if (a[m][n] == 'N')
				{
					if ((g - m == 1 || g - m == -1 || g - m == 2 || g - m == -2) && (h - n == 1 || h - n == -1 || h - n == 2 || h - n == -2))

					{

						xx = m;
						yy = n;
						blackflag = 1;
						Ncheck = 1;
					}
				}
				if (a[m][n] == 'R')
				{

					int a = 0;
					int kky = 0;
					int x = 0;
					int ap = 0;
					a = moverook(m, n, g, h);

					if (a == 1)
					{

						xx = m;
						yy = n;
						blackflag = 1;
						Rcheck = 1;
					}
				}
				if (a[m][n] == 'Q')
				{
					int a = 0;
					int kky = 0;
					int x = 0;
					int ap = 0;
					a = movequeen(m, n, g, h);

					if (a == 1)
					{

						xx = m;
						yy = n;
						blackflag = 1;
						Qcheck = 1;
					}
				}
				if (a[m][n] == 'K')
				{
					if ((g == m + 1 && h == n + 1) || (g == m + 1 && h == n) || (g == m + 1 && h == n - 1) || (g == m && h == n - 1) || (g == m && h == n + 1) || (g == m - 1 && h == n - 1) || (g == m - 1 && h == n) || (g == m - 1 && h == n + 1))
					{

						blackflag = 1;
					}
				}
			}
		}
		if (blackflag == 1)
		{
			return 1;
		}
		else
			return 0;
	}
	int whitecheckmate()
	{

		int t;
		t = 0;
		int m, n;
		m = 0;
		n = 0;
		int u = 0;
		int v = 0;
		int x = 0;
		t = whitecheck();
		if (t == 1)
		{
			for (int i = 1; i < 9; i++)
			{
				for (int j = 1; j < 9; j++)
				{
					if (a[i][j] == 'K')
					{

						m = i;
						n = j;
					}
				}
			}
			if (a[m + 1][n + 1] == '.' || (a[m + 1][n + 1] > 'a' && a[m + 1][n + 1] < 'z'))
			{
				if (m + 1 == 9 || n + 1 == 9)
				{
				}
				else
				{

					u = whitecheck(m + 1, n + 1);

					if (u == 0)
						goto label;
				}
			}
			if (a[m + 1][n] == '.' || (a[m + 1][n] > 'a' && a[m + 1][n] < 'z'))
			{
				if (m + 1 == 9)
				{
				}
				else
				{

					u = whitecheck(m + 1, n);

					if (u == 0)
						goto label;
				}
			}
			if (a[m + 1][n - 1] == '.' || (a[m + 1][n - 1] > 'a' && a[m + 1][n - 1] < 'z'))
			{

				if (m + 1 == 9 || n - 1 == 0)
				{
				}
				else
				{

					u = whitecheck(m + 1, n - 1);

					if (u == 0)
						goto label;
				}
			}
			if (a[m][n + 1] == '.' || (a[m][n + 1] > 'a' && a[m][n + 1] < 'z'))
			{

				if (n + 1 == 9)
				{
				}
				else
				{
					u = whitecheck(m, n + 1);

					if (u == 0)
						goto label;
				}
			}
			if (a[m - 1][n + 1] == '.' || (a[m - 1][n + 1] > 'a' && a[m - 1][n + 1] < 'z'))
			{
				if (n + 1 == 9 || m - 1 == 0)
				{
				}
				else
				{

					u = whitecheck(m - 1, n + 1);

					if (u == 0)
						goto label;
				}
			}
			if (a[m - 1][n] == '.' || (a[m - 1][n] > 'a' && a[m - 1][n] < 'z'))
			{
				if (m - 1 == 0)
				{
				}
				else
				{

					u = whitecheck(m - 1, n);

					if (u == 0)
						goto label;
				}
			}
			if (a[m][n - 1] == '.' || (a[m][n - 1] > 'a' && a[m][n - 1] < 'z'))
			{
				if (n - 1 == 0)
				{
				}
				else
				{

					u = whitecheck(m, n - 1);

					if (u == 0)
						goto label;
				}
			}
			if (a[m - 1][n - 1] == '.' || (a[m - 1][n - 1] > 'a' && a[m - 1][n - 1] < 'z'))
			{
				if (m - 1 == 0 || n - 1 == 0)
				{
				}
				else
				{

					u = whitecheck(m - 1, n - 1);

					if (u == 0)
						goto label;
				}
			}
			if (pcheck == 1 || ncheck == 1 || bcheck == 1 || rcheck == 1 || qcheck == 1)
			{
				whitecheck();
				v = killb(xx, yy);
				if (v == 1)
					goto label;
			}
			if (bcheck == 1 || rcheck == 1 || qcheck == 1)
			{
				whitecheck();
				x = whiteblock(xx, yy);
				if (x == 1)
					goto label;
			}
		}

	label:
		if (u == 0 || v == 1 || x == 1)
			return 1;
		else
		{

			cout << "White player is in checkmate, CONGRATULATIONS, Black player has won\n";
			display();
			win = 1;
			complete();
			return 0;
		}
	}
	int blackcheckmate()
	{

		int t;
		t = 0;
		int m, n;
		m = 0;
		n = 0;
		int u = 0;
		int v = 0;
		int x = 0;

		t = blackcheck();

		if (t == 1)
		{

			for (int i = 1; i < 9; i++)
			{
				for (int j = 1; j < 9; j++)
				{
					if (a[i][j] == 'k')
					{
						m = i;
						n = j;
						break;
					}
				}
			}

			if (a[m + 1][n + 1] == '.' || (a[m + 1][n + 1] > 'A' && a[m + 1][n + 1] < 'Z'))
			{
				if (m + 1 == 9 || n + 1 == 9)
				{
				}
				else
				{
					u = blackcheck(m + 1, n + 1);
					reassign();
					if (u == 0)
					{

						goto label;
					}
				}
			}
			if (a[m + 1][n] == '.' || (a[m + 1][n] > 'A' && a[m + 1][n] < 'Z'))
			{
				if (m + 1 == 9)
				{
				}
				else
				{
					u = blackcheck(m + 1, n);
					reassign();
					if (u == 0)
					{

						goto label;
					}
				}
			}
			if (a[m + 1][n - 1] == '.' || (a[m + 1][n - 1] > 'A' && a[m + 1][n - 1] < 'Z'))
			{

				if (m + 1 == 9 || n - 1 == 0)
				{
				}
				else
				{
					u = blackcheck(m + 1, n - 1);
					reassign();
					if (u == 0)
					{

						goto label;
					}
				}
			}
			if (a[m][n + 1] == '.' || (a[m][n + 1] > 'A' && a[m][n + 1] < 'Z'))
			{

				if (n + 1 == 9)
				{
				}
				else
				{
					u = blackcheck(m, n + 1);
					reassign();
					if (u == 0)
					{

						goto label;
					}
				}
			}
			if (a[m - 1][n + 1] == '.' || (a[m - 1][n + 1] > 'A' && a[m - 1][n + 1] < 'Z'))
			{
				if (n + 1 == 9 || m - 1 == 0)
				{
				}
				else
				{
					u = blackcheck(m - 1, n + 1);
					reassign();
					if (u == 0)
					{

						goto label;
					}
				}
			}
			if (a[m - 1][n] == '.' || (a[m - 1][n] > 'A' && a[m - 1][n] < 'Z'))
			{
				if (m - 1 == 0)
				{
				}
				else
				{
					u = blackcheck(m - 1, n);
					reassign();
					if (u == 0)
					{

						goto label;
					}
				}
			}
			if (a[m][n - 1] == '.' || (a[m][n - 1] > 'A' && a[m][n - 1] < 'Z'))
			{
				if (n - 1 == 0)
				{
				}
				else
				{
					u = blackcheck(m, n - 1);
					reassign();
					if (u == 0)
					{

						goto label;
					}
				}
			}
			if (a[m - 1][n - 1] == '.' || (a[m - 1][n - 1] > 'A' && a[m - 1][n - 1] < 'Z'))
			{
				if (m - 1 == 0 || n - 1 == 0)
				{
				}
				else
				{
					u = blackcheck(m - 1, n - 1);
					reassign();
					if (u == 0)
					{

						goto label;
					}
				}
			}
			blackcheck();
			if (Pcheck == 1 || Ncheck == 1 || Bcheck == 1 || Rcheck == 1 || Qcheck == 1)
			{

				v = killw(xx, yy);
				if (v == 1)
				{

					goto label;
				}
			}
			blackcheck();
			if (Bcheck == 1 || Rcheck == 1 || Qcheck == 1)
			{
				x = blackblock(xx, yy);
				if (x == 1)
				{

					goto label;
				}
			}
		}
	label:
		if (u == 0 || v == 1 || x == 1)
		{
			return 1;
		}
		else
		{

			cout << "Black player in is checkmate, CONGRATULATIONS, White player has won\n";
			display();
			win = 1;
			complete();
			return 0;
		}
	}
	int killw(int xx, int yy) //to see if piece which is checking can be killed
	{

		int v = 0;

		for (int i = 1; i < 9; i++)
		{
			for (int j = 1; j < 9; j++)
			{
				if (a[i][j] == 'p')
				{
					v = movepawn(i, j, xx, yy);
					if (v == 1)
						goto label;
				}
				if (a[i][j] == 'n')
				{
					v = moveknight(i, j, xx, yy);
					if (v == 1)
						goto label;
				}
				if (a[i][j] == 'b')
				{
					v = movebishop(i, j, xx, yy);
					if (v == 1)
						goto label;
				}
				if (a[i][j] == 'r')
				{
					v = moverook(i, j, xx, yy);
					if (v == 1)
						goto label;
				}
				if (a[i][j] == 'q')
				{
					v = movequeen(i, j, xx, yy);
					if (v == 1)
						goto label;
				}
				if (a[i][j] == 'K')
				{
					v = moveking(i, j, xx, yy);
					if (v == 1)
						goto label;
				}
			}
		}
	label:
		if (v == 1)
			return 1;
		else
			return 0;
	}
	int killb(int xx, int yy) //to see if piece which is checking can be killed
	{

		int v = 0;
		for (int i = 1; i < 9; i++)
		{
			for (int j = 1; j < 9; j++)
			{
				if (a[i][j] == 'P')
				{
					v = movepawn(i, j, xx, yy);
					if (v == 1)
						goto label;
				}
				if (a[i][j] == 'N')
				{
					v = moveknight(i, j, xx, yy);
					if (v == 1)
						goto label;
				}
				if (a[i][j] == 'B')
				{
					v = movebishop(i, j, xx, yy);
					if (v == 1)
						goto label;
				}
				if (a[i][j] == 'R')
				{
					v = moverook(i, j, xx, yy);
					if (v == 1)
						goto label;
				}
				if (a[i][j] == 'Q')
				{
					v = movequeen(i, j, xx, yy);
					if (v == 1)
						goto label;
				}
				if (a[i][j] == 'K')
				{
					v = moveking(i, j, xx, yy);
					if (v == 1)
						goto label;
				}
			}
		}
	label:
		if (v == 1)
			return 1;
		else
			return 0;
	}
	int movecheck(int aa, int bb, int cc, int dd) //to see if move can be done
	{

		int v = 0;
		v = movepawn(aa, bb, cc, dd);
		if (v == 1)
			goto pos;
		v = movebishop(aa, bb, cc, dd);
		if (v == 1)
			goto pos;
		v = moveknight(aa, bb, cc, dd);
		if (v == 1)
			goto pos;
		v = moverook(aa, bb, cc, dd);
		if (v == 1)
			goto pos;
		v = movequeen(aa, bb, cc, dd);
		if (v == 1)
			goto pos;

	pos:
		if (v == 1)
			return 1;
		else
			return 0;
	}
	int whiteblock(int xx, int yy) //to block path between attacking piece and king
	{

		int v = 0;
		int d = 0;
		int e = 0;
		int f = 0;
		int g = 0;
		if (a[xx][yy] == 'q' || a[xx][yy] == 'b' || a[xx][yy] == 'r')
		{
			for (int i = 1; i < 9; i++)
			{
				for (int j = 1; j < 9; j++)
				{
					if (a[i][j] == 'K')
					{
						d = i;
						e = j;
					}
				}
			}
			if ((d + 1 == xx && e + 1 == yy) || (d + 1 == xx && e == yy) || (d + 1 == xx && e - 1 == yy) ||
				(d + 1 == xx && e + 1 == yy) || (d == xx && e + 1 == yy) || (d - 1 == xx && e + 1 == yy) || (d == xx && e + 1 == yy) || (d == xx && e - 1 == yy))
				return 0;
			if (xx - d == yy - e || xx - d == -(yy - e)) //diagonal movement
			{
				if (xx > d && yy > e)
				{
					for (int p = -8; p <= xx - d; p++)
					{
						for (int q = 8; q <= yy - e; q++)
						{
							if (a[xx + p][yy + q] == '.')
							{
								for (int m = 1; m < 9; m++)
								{
									for (int n = 1; n < 9; n++)
									{
										if (a[m][n] > 'A' && a[m][n] < 'Z')
										{
											v = movecheck(m, n, xx + p, yy + q);
											if (v == 1)
												goto pos;
										}
									}
								}
							}
						}
					}
				}
				if (xx > d && yy < e)
				{
					for (int p = 8; p <= xx - d; p++)
					{
						for (int q = 8; q >= yy - e; q--)
						{
							if (a[xx + p][yy + q] == '.')
							{
								for (int m = 1; m < 9; m++)
								{
									for (int n = 1; n < 9; n++)
									{
										if (a[m][n] > 'A' && a[m][n] < 'Z')
										{
											v = movecheck(m, n, xx + p, yy + q);
											if (v == 1)
												goto pos;
										}
									}
								}
							}
						}
					}
				}
				if (xx < d && yy > e)
				{
					for (int p = 8; p >= xx - d; p--)
					{
						for (int q = -8; q <= yy - e; q++)
						{
							if (a[xx + p][yy + q] == '.')
							{
								for (int m = 1; m < 9; m++)
								{
									for (int n = 1; n < 9; n++)
									{
										if (a[m][n] > 'A' && a[m][n] < 'Z')
										{
											v = movecheck(m, n, xx + p, yy + q);
											if (v == 1)
												goto pos;
										}
									}
								}
							}
						}
					}
				}
				if (xx < d && yy < e)
				{
					for (int p = 8; p >= xx - d; p--)
					{
						for (int q = 8; q >= yy - e; q--)
						{
							if (a[xx + p][yy + q] == '.')
							{
								for (int m = 1; m < 9; m++)
								{
									for (int n = 1; n < 9; n++)
									{
										if (a[m][n] > 'A' && a[m][n] < 'Z')
										{
											v = movecheck(m, n, xx + p, yy + q);
											if (v == 1)
												goto pos;
										}
									}
								}
							}
						}
					}
				}
			}
			if (xx == d && yy != e || yy == e && xx != d) //horizontal and vertical movement
			{

				if (xx > d && yy == e) //top to bottom
				{
					for (int p = -8; p <= xx + d; p++)
					{
						if (a[xx + p][yy] == '.')
						{
							for (int m = 1; m < 9; m++)
							{
								for (int n = 1; n < 9; n++)
								{
									if (a[m][n] > 'A' && a[m][n] < 'Z')
									{
										v = movecheck(m, n, xx + p, yy);
										if (v == 1)
											goto pos;
									}
								}
							}
						}
					}
				}
				if (xx < d && yy == e) //bottom to top
				{
					for (int p = 8; p >= xx - d; p--)
					{
						if (a[xx + p][yy] == '.')
						{
							for (int m = 1; m < 9; m++)
							{
								for (int n = 1; n < 9; n++)
								{
									if (a[m][n] > 'A' && a[m][n] < 'Z')
									{
										v = movecheck(m, n, xx + p, yy);
										if (v == 1)
											goto pos;
									}
								}
							}
						}
					}
				}
				if (xx == d && yy > e) //right to left
				{
					for (int q = 8; q >= e - yy; q--)
					{
						if (a[xx][yy + q] == '.')
						{
							for (int m = 1; m < 9; m++)
							{
								for (int n = 1; n < 9; n++)
								{
									if (a[m][n] > 'A' && a[m][n] < 'Z')
									{
										v = movecheck(m, n, xx, yy + q);
										if (v == 1)
											goto pos;
									}
								}
							}
						}
					}
				}
				if (xx == d && yy < e) //left to right
				{
					for (int q = -8; q <= e - yy; q++)
					{
						if (a[xx][yy + q] == '.')
						{
							for (int m = 1; m < 9; m++)
							{
								for (int n = 1; n < 9; n++)
								{
									if (a[m][n] > 'A' && a[m][n] < 'Z')
									{
										v = movecheck(m, n, xx, yy + q);
										if (v == 1)
											goto pos;
									}
								}
							}
						}
					}
				}
			}
		}
	pos:
		if (v == 1)
			return 1;
		else
			return 0;
	}
	int blackblock(int xx, int yy) //to block path between attacking piece and king
	{

		int v = 0;
		int d = 0;
		int e = 0;
		int f = 0;
		int g = 0;
		if (a[xx][yy] == 'Q' || a[xx][yy] == 'B' || a[xx][yy] == 'R')
		{
			for (int i = 1; i < 9; i++)
			{
				for (int j = 1; j < 9; j++)
				{
					if (a[i][j] == 'k')
					{
						d = i;
						e = j;
					}
				}
			}
			if ((d + 1 == xx && e + 1 == yy) || (d + 1 == xx && e == yy) || (d + 1 == xx && e - 1 == yy) ||
				(d + 1 == xx && e + 1 == yy) || (d == xx && e + 1 == yy) || (d - 1 == xx && e + 1 == yy) || (d == xx && e + 1 == yy) || (d == xx && e - 1 == yy))
				return 0;

			if (xx - d == yy - e || xx - d == -(yy - e)) //diagonal movement
			{
				if (xx > d && yy > e)
				{

					for (int p = -8; p <= xx - d; p++)
					{
						for (int q = -8; q <= yy - e; q++)
						{
							if (a[xx + p][yy + q] == '.')
							{
								for (int m = 1; m < 9; m++)
								{
									for (int n = 1; n < 9; n++)
									{
										if (a[m][n] > 'a' && a[m][n] < 'z')
										{
											v = movecheck(m, n, xx + p, yy + q);
											if (v == 1)
											{

												goto pos;
											}
										}
									}
								}
							}
						}
					}
				}
				if (xx > d && yy < e)
				{

					for (int p = -8; p <= xx - d; p++)
					{
						for (int q = 8; q >= yy - e; q--)
						{
							if (a[xx + p][yy + q] == '.')
							{
								for (int m = 1; m < 9; m++)
								{
									for (int n = 1; n < 9; n++)
									{
										if (a[m][n] > 'a' && a[m][n] < 'z')
										{
											v = movecheck(m, n, xx + p, yy + q);
											if (v == 1)
											{

												goto pos;
											}
										}
									}
								}
							}
						}
					}
				}
				if (xx < d && yy > e)
				{

					for (int p = 8; p >= xx - d; p--)
					{
						for (int q = -8; q <= yy - e; q++)
						{
							if (a[xx + p][yy + q] == '.')
							{
								for (int m = 1; m < 9; m++)
								{
									for (int n = 1; n < 9; n++)
									{
										if (a[m][n] > 'a' && a[m][n] < 'z')
										{
											v = movecheck(m, n, xx + p, yy + q);
											if (v == 1)
											{

												goto pos;
											}
										}
									}
								}
							}
						}
					}
				}
				if (xx < d && yy < e)
				{

					for (int p = 8; p >= xx - d; p--)
					{
						for (int q = 8; q >= yy - e; q--)
						{
							if (a[xx + p][yy + q] == '.')
							{
								for (int m = 1; m < 9; m++)
								{
									for (int n = 1; n < 9; n++)
									{
										if (a[m][n] > 'a' && a[m][n] < 'z')
										{
											v = movecheck(m, n, xx + p, yy + q);
											if (v == 1)
											{

												goto pos;
											}
										}
									}
								}
							}
						}
					}
				}
			}
			if (xx == d && yy != e || yy == e && xx != d) //horizontal and vertical movement
			{

				if (xx > d && yy == e) //top to bottom
				{

					for (int p = -8; p <= xx + d; p++)
					{
						if (a[xx + p][yy] == '.')
						{
							for (int m = 1; m < 9; m++)
							{
								for (int n = 1; n < 9; n++)
								{
									if (a[m][n] > 'a' && a[m][n] < 'z')
									{
										v = movecheck(m, n, xx + p, yy);
										if (v == 1)
										{

											goto pos;
										}
									}
								}
							}
						}
					}
				}
				if (xx < d && yy == e) //bottom to top
				{

					for (int p = 8; p >= xx - d; p--)
					{
						if (a[xx + p][yy] == '.')
						{
							for (int m = 1; m < 9; m++)
							{
								for (int n = 1; n < 9; n++)
								{
									if (a[m][n] > 'a' && a[m][n] < 'z')
									{
										v = movecheck(m, n, xx + p, yy);
										if (v == 1)
										{

											goto pos;
										}
									}
								}
							}
						}
					}
				}
				if (xx == d && yy > e) //right to left
				{

					for (int q = 8; q >= e - yy; q--)
					{
						if (a[xx][yy + q] == '.')
						{
							for (int m = 1; m < 9; m++)
							{
								for (int n = 1; n < 9; n++)
								{
									if (a[m][n] > 'a' && a[m][n] < 'z')
									{
										v = movecheck(m, n, xx, yy + q);
										if (v == 1)
										{

											goto pos;
										}
									}
								}
							}
						}
					}
				}
				if (xx == d && yy < e) //left to right
				{

					for (int q = -8; q <= e - yy; q++)
					{
						if (a[xx][yy + q] == '.')
						{
							for (int m = 1; m < 9; m++)
							{
								for (int n = 1; n < 9; n++)
								{
									if (a[m][n] > 'a' && a[m][n] < 'z')
									{
										v = movecheck(m, n, xx, yy + q);
										if (v == 1)
										{

											goto pos;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	pos:
		if (v == 1)
			return 1;
		else
			return 0;
	}

	void copy1()
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				d[i][j] = a[i][j];
			}
		}
	}
	void copy2()
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				a[i][j] = d[i][j];
			}
		}
	}

	int whitestalemate()
	{
		int legal = -1;
		int p = -1;
		copy1();
		for (int i = 1; i < 9; i++)
		{

			for (int j = 1; j < 9; j++)
			{

				if (a[i][j] == 'P')
				{

					for (int m = -1; m >= -2; m--)
					{
						for (int n = -1; n <= 1; n++)
						{
							p = movepawn(i, j, i + m, j + n);
							if (p == 1)
							{
								legal = wswap(i, j, i + m, j + n);
								if (legal == 0)
									goto label;
								else
									staleundo(i, j, i + m, j + n);
							}
						}
					}
				}
				if (a[i][j] == 'N')
				{
					for (int m = -2; m <= 2; m++)
					{
						for (int n = -2; n <= 2; n++)
						{
							p = moveknight(i, j, i + m, j + m);
							if (p == 1)
							{

								legal = wswap(i, j, i + m, j + n);
								if (legal == 0)
									goto label;
								else
									staleundo(i, j, i + m, j + n);
							}
						}
					}
				}
				if (a[i][j] == 'B')
				{

					for (int m = 1; m < 9; m++)
					{
						for (int n = 1; n < 9; n++)
						{
							p = movebishop(i, j, m, n);
							if (p == 1)
							{
								legal = wswap(i, j, m, n);
								if (legal == 0)
									goto label;
								else
									staleundo(i, j, m, n);
							}
						}
					}
				}
				if (a[i][j] == 'R')
				{

					for (int m = 1; m < 9; m++)
					{
						for (int n = 1; n < 9; n++)
						{
							p = moverook(i, j, m, n);
							if (p == 1)
							{
								legal = wswap(i, j, m, n);
								if (legal == 0)
									goto label;
								else
									staleundo(i, j, m, n);
							}
						}
					}
				}
				if (a[i][j] == 'Q')
				{

					for (int m = 1; m < 9; m++)
					{
						for (int n = 1; n < 9; n++)
						{
							p = movequeen(i, j, m, n);
							if (p == 1)
							{
								legal = wswap(i, j, m, n);
								if (legal == 0)
									goto label;
								else
									staleundo(i, j, m, n);
							}
						}
					}
				}
				if (a[i][j] == 'K')
				{

					for (int m = -1; m <= 1; m++)
					{
						for (int n = -1; n <= 1; n++)
						{
							if ((i + m == i) && (j + n == j))
								continue;
							p = moveking(i, j, i + m, j + n);
							if (p == 1)
							{

								legal = wswap(i, j, i + m, j + n);

								if (legal == 0)
								{

									goto label;
								}
								else
									staleundo(i, j, i + m, j + n);
							}
						}
					}
				}
			}
		}
		if (legal == -1 || legal == 1)
		{

			return 1;
		}
	label:

		if (legal == 0)
		{

			copy2();

			return 0;
		}
	}
	int blackstalemate()
	{
		int legal = -1;
		int p = -1;
		copy1();
		for (int i = 1; i < 9; i++)
		{
			for (int j = 1; j < 9; j++)
			{
				if (a[i][j] == 'p')
				{
					for (int m = 1; m <= 2; m++)
					{
						for (int n = -1; n <= 1; n++)
						{
							p = movepawn(i, j, i + m, j + n);
							if (p == 1)
							{
								legal = bswap(i, j, i + m, j + n);
								if (legal == 0)
									goto label;
								else
									staleundo(i, j, i + m, j + n);
							}
						}
					}
				}
				if (a[i][j] == 'n')
				{
					for (int m = -2; m <= 2; m++)
					{
						for (int n = -2; n <= 2; n++)
						{
							p = moveknight(i, j, i + m, j + m);
							if (p == 1)
							{

								legal = bswap(i, j, i + m, j + n);
								if (legal == 0)
									goto label;
								else
									staleundo(i, j, i + m, j + n);
							}
						}
					}
				}
				if (a[i][j] == 'b')
				{
					for (int m = 1; m < 9; m++)
					{
						for (int n = 1; n < 9; n++)
						{
							p = movebishop(i, j, m, n);
							if (p == 1)
							{
								legal = bswap(i, j, m, n);
								if (legal == 0)
									goto label;
								else
									staleundo(i, j, m, n);
							}
						}
					}
				}
				if (a[i][j] == 'r')
				{
					for (int m = 1; m < 9; m++)
					{
						for (int n = 1; n < 9; n++)
						{
							p = moverook(i, j, m, n);
							if (p == 1)
							{
								legal = bswap(i, j, m, n);
								if (legal == 0)
									goto label;
								else
									staleundo(i, j, m, n);
							}
						}
					}
				}
				if (a[i][j] == 'q')
				{
					for (int m = 1; m < 9; m++)
					{
						for (int n = 1; n < 9; n++)
						{
							p = movequeen(i, j, m, n);
							if (p == 1)
							{
								legal = bswap(i, j, m, n);
								if (legal == 0)
									goto label;
								else
									staleundo(i, j, m, n);
							}
						}
					}
				}
				if (a[i][j] == 'k')
				{
					for (int m = -1; m <= 1; m++)
					{
						for (int n = -1; n <= 1; n++)
						{
							p = moveking(i, j, i + m, j + n);
							if (p == 1)
							{
								legal = bswap(i, j, i + m, j + n);
								if (legal == 0)
									goto label;
								else
									staleundo(i, j, i + m, j + n);
							}
						}
					}
				}
			}
		}
		if (legal == -1 || legal == 1)
		{
			return 1;
		}
	label:
		if (legal == 0)
		{
			copy2();
			return 0;
		}
	}
	int gameover()
	{
		stalemate = 0;
		win = 0;
		int a = 0;
		cout << "Enter 1 to undo, 2 to play again or any other key to exit the game\n";
		cin >> a;
		if (a == 1)
		{

			return 1;
		}
		else if (a == 2)
		{
			turn = 1;
			undostart = 0;
			printf("\033[2J\033[1;1H");
			return 2;
		}
		else
		{

			return 0;
		}
	}

	int end()
	{
		if (stalemate == 1 || win == 1)
		{
			cout << "Game over\n";
			return 1;
		}
		else
			return 0;
	}

	void reassign()
	{
		xx = 0;
		yy = 0;
		Pcheck = 0;
		Bcheck = 0;
		Ncheck = 0;
		Qcheck = 0;
		Rcheck = 0;
		pcheck = 0;
		bcheck = 0;
		ncheck = 0;
		qcheck = 0;
		rcheck = 0;
	}

  public:
	void initial();
	void complete()
	{
		f[0] = 0;
		f[1] = 0;
		int hj = 0;
		while (1)
		{
			int o = -1;
			int n = 2;
			n = end();
			if (n == 1)
			{
				o = gameover();
				if (o == 0)
					exit(1);
				if (o == 1)
				{

					win = 0;
					stalemate = 0;
					undomove();
				}
				if (o == 2)
				{
					initial();
					complete();
				}
			}

			turn++;
			if (turn % 2 == 0)
				cout << "\nWhite's turn\n";
			else
				cout << "\nBlack's turn\n";
			checkpostmove();
			reassign();

			display();
			cout << endl;
			input();
		}
	}
};

void chess::initial()
{

	brcastle = 0;
	blcastle = 0;
	wcastle = 0;
	bcastle = 0;
	bking = 0;
	wrcastle = 0;
	wlcastle = 0;
	wking = 0;
	ifstream fin;
	fin.open("chessboard.txt");

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			fin.get(a[i][j]);
			// cout<<(int)a[i][j]<<" ";
		}
		cout<<"\n";
	}
}

void chess::display()
{

	for (int i = 0; i < 10; i++)
	{

		for (int j = 0; j < 10; j++)
		{
			if (a[i][j] == 'P')
				cout << "P(w)"
					 << "\t";
			else if (a[i][j] == 'p')
				cout << "P(b)"
					 << "\t";
			else if (a[i][j] == 'B')
				cout << "B(w)"
					 << "\t";
			else if (a[i][j] == 'b' && (i != 0 && i != 9))
				cout << "B(b)"
					 << "\t";
			else if (a[i][j] == 'N')
				cout << "N(w)"
					 << "\t";
			else if (a[i][j] == 'n')
				cout << "N(b)"
					 << "\t";
			else if (a[i][j] == 'Q')
				cout << "Q(w)"
					 << "\t";
			else if (a[i][j] == 'q')
				cout << "Q(b)"
					 << "\t";
			else if (a[i][j] == 'R')
				cout << "R(w)"
					 << "\t";
			else if (a[i][j] == 'r')
				cout << "R(b)"
					 << "\t";
			else if (a[i][j] == 'K')
				cout << "K(w)"
					 << "\t";
			else if (a[i][j] == 'k')
				cout << "K(b)"
					 << "\t";
			else
				cout << a[i][j] << "\t";
		}

		cout << endl
			 << endl
			 << endl;
	}
}

int main()
{
	cout << "Welcome to chess game\n";
	cout << "The white piece have 'w' written next to them and the black pieces have 'b' written next to them\n";
	cout << "P-pawn, B-Bishop, N-Knight, R-Rook, Q-Queen, K-King\n";
	chess test;
	test.initial();
	test.complete();
	return 0;
}