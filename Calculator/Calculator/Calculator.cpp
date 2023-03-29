#include <iostream>
using namespace std;

class clsCalculator {

private:

	string LastOperation = "";
	float PreviousResult = 0;
	float LastNumber = 0;
	float _Result = 0;


	bool IsZero(int Number) {
		return Number == 0;
	}


public:

	void Clear() {
		LastNumber = 0;
		PreviousResult = 0;
		LastOperation = "Clear";
		_Result = 0;
	}

	void Add(float number) {
		LastNumber = number;
		PreviousResult = _Result;
		LastOperation = "Adding";
		_Result += number;
	}

	void Subtract(float number) {
		PreviousResult = _Result;
		LastNumber = number;
		LastOperation = "Subtracting";

		_Result -= number;
	}

	void Multiply(float number) {
		LastNumber = number;
		PreviousResult = _Result;
		LastOperation = "Multiplying";
		_Result *= number;
	}


	void Divide(float number) {

		LastNumber = number;
		if (IsZero(number)) {
			number = 1;
		}
		PreviousResult = _Result;
		LastOperation = "Dividing";
		_Result /= number;
	}
	
	float GetFinalResults() {
		return _Result;
	}
	void CancelLastResult() {
		LastNumber = 0;
		LastOperation = "Canceling Last Operation";
		_Result = PreviousResult;

	}
	void PrintResults() {
		cout << "Result ";
		cout <<"After "  << LastOperation << " " << LastNumber << " is: " << _Result << endl;
	}



};

int main()
{
	clsCalculator Calculator1;

	Calculator1.Clear();
	Calculator1.Add(10);
	Calculator1.PrintResults();

	Calculator1.Add(100);
	Calculator1.PrintResults();

	Calculator1.Subtract(20);
	Calculator1.PrintResults();

	Calculator1.Divide(0);
	Calculator1.PrintResults();

	Calculator1.Divide(2);
	Calculator1.PrintResults();


	Calculator1.Multiply(3);
	Calculator1.PrintResults();

	Calculator1.CancelLastResult();
	Calculator1.PrintResults();


	Calculator1.Clear();
	Calculator1.PrintResults();


	system("pause>0");

	return 0;
}