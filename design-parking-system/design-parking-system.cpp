// #include <bits/stdc++.h>
// using namespace std;

// NM... POD
// first time encounter of design and OOPS prob

class ParkingSystem
{
public:
    int bgLim, medLim, smLim;

    int bgCnt, mdCnt, smCnt;

    ParkingSystem(int big, int medium, int small)
    {
        this->bgLim = big;
        this->medLim = medium;
        this->smLim = small;

        this->bgCnt = 0;
        this->mdCnt = 0;
        this->smCnt = 0;
    }

    bool addCar(int carType)
    {
        if (carType == 1)
        {
            if (this->bgCnt < this->bgLim)
            {
                this->bgCnt++;
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (carType == 2)
        {
            if (this->mdCnt < this->medLim)
            {
                this->mdCnt++;
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (carType == 3)
        {
            if (this->smCnt < this->smLim)
            {
                this->smCnt++;
                return true;
            }
            else
            {
                return false;
            }
        }

        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */