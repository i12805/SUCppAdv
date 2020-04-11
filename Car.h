#include <string>

using namespace std;

class Car
{
	private:
		std::string Brand;
		std::string Model;
		int Year;
	public:

		Car(std::string strBrand, std::string strModel, int s32Year):Brand(strBrand), Model(strModel), Year(s32Year){}

		std::string GetBrand() const
		{
			return(this->Brand);
		}
	
		std::string GetModel() const
		{
			return(this->Model);
		}

		int GetYear() const
		{
			return(this->Year);
		}
};

