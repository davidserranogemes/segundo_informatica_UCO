#include <list>

using namespace std;
class Contador{
	private:
		int entero_;
		int min_;
		int max_;
		list<int> previo_;
		void ultValor(int last);
	public:
		Contador(int min=0,int max=1000, int init=0){min_=min;max_=max;if((init<min_)||(init>max_)){entero_=0;}else{entero_=init;}};
		
		Contador operator=(int aux);
		Contador operator=(Contador aux);
		
		Contador operator++(void);
		Contador operator++(int);

		Contador operator--(void);
		Contador operator--(int);

		friend Contador operator+(Contador c, int i);
		friend Contador operator+(int i, Contador c);

		friend Contador operator-(Contador c, int i);
		friend Contador operator-(int i, Contador c);
		
		bool undo(int n=1);

		int get(){return(entero_);};
		int getMax(){return(max_);};
		int getMin(){return(min_);};
};
