#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;



typedef struct {
	string year;
	string month;
	string date;
}Node;


typedef struct {
	char terms_name;
	int terms_number;
}t_Node;


string s;
vector<int> result;
vector<char> kind_term;
vector<string> start_date;
vector<Node> new_srt_date;
vector<t_Node> new_terms;




vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
	for (int i = 0; i < privacies.size(); i++)
	{
		for (int j = 0; j < privacies[i].size() - 2; j++)
		{
			s += privacies[i][j];
		}
		start_date.push_back(s);
		s = "";
		kind_term.push_back(privacies[i][11]);
	}

	string year;
	string month;
	string date;
	for (int j = 0; j < start_date.size(); j++)
	{
		year = "";
		month = "";
		date = "";


		for (int i = 0; i < 4; i++)
		{

			year += start_date[j][i];

		}

		for (int i = 5; i < 7; i++)
		{
			month += start_date[j][i];


		}

		for (int i = 8; i < 10; i++)
		{
			date += start_date[j][i];
		}

		//new_srt_date ={"2021","05","02"}

		new_srt_date.push_back({ year, month, date });

		//ÃÊ±âÈ­

	}

	vector<Node> new_today;
	string td_month;
	string td_year;
	string td_date;
	//today ÆÄ½Ì
	for (int i = 0; i < 4; i++)
	{

		td_year += today[i];

	}

	for (int i = 5; i < 7; i++)
	{

		td_month += today[i];


	}

	for (int i = 8; i < 10; i++)
	{

		td_date += today[i];
	}

	new_today.push_back({ td_year, td_month, td_date });

	string two_word;
	//terms ÆÄ½Ì
	for (int i = 0; i < terms.size(); i++)
	{
		two_word = "";
		if (terms[i].size() == 3)
		{
			new_terms.push_back({ terms[i][0],int(terms[i][2] - '0') });
		}
		else if (terms[i].size() == 4)
		{

			for (int j = 2; j < 4; j++)
			{

				two_word += terms[i][j];

			}
			new_terms.push_back({ terms[i][0], stoi(two_word) });
		}
		else if (terms[i].size() == 5)
		{
			for (int j = 2; j < 5; j++)
			{

				two_word += terms[i][j];

			}
			new_terms.push_back({ terms[i][0], stoi(two_word) });
		}
	}




	int sum_month;
	int sum_year;
	int sum_date;

	int new_td_year = stoi(td_year);
	int new_td_month = stoi(td_month);
	int new_td_date = stoi(td_date);

	//ºñ±³
	for (int i = 0; i < privacies.size(); i++)
	{
		sum_month = stoi(new_srt_date[i].month);
		sum_year = stoi(new_srt_date[i].year);
		sum_date = stoi(new_srt_date[i].date) - 1;
		for (int j = 0; j < terms.size(); j++)
		{
			if (kind_term[i] != new_terms[j].terms_name) continue;
			if (sum_date == 0)
			{
				sum_date = 28;
				sum_month -= 1;
			}
			if (sum_month == 0)
			{
				sum_month = 12;
				sum_year -= 1;
			}

			sum_month += new_terms[j].terms_number;
			while (sum_month > 12)
			{
				sum_month -= 12;
				sum_year += 1;
			}

		}
		if (new_td_year > sum_year)
		{
			result.push_back(i + 1);
			continue;
		}
		else if (new_td_year == sum_year && new_td_month > sum_month)
		{
			result.push_back(i + 1);
			continue;
		}
		else if (new_td_year == sum_year && new_td_month == sum_month && new_td_date > sum_date)
		{
			result.push_back(i + 1);
			continue;
		}



	}


	return result;
}