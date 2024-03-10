#include <iostream>
#include <string>

using namespace std;
typedef string PhoneNumber;
typedef string EMail;
typedef string TextMessage;

class CallableByNamePhone
{
public:
	CallableByNamePhone() = delete;
	virtual bool dial(const string &firstName, const string &lastName) = 0;
};

class SMSSendablePhone
{
public:
	SMSSendablePhone() = delete;
	virtual bool sendSMS(const PhoneNumber &phoneNum) = 0;
	virtual bool sendSMS(const string &firstName, const string &lastName) = 0;
};

class MMSSendablePhone
{
public:
	MMSSendablePhone() = delete;
	virtual bool sendMMS(const PhoneNumber &phoneNum) = 0;
	virtual bool sendMMS(const string &firstName, const string &lastName) = 0;
};

class Phone
{
public:
	Phone() = delete;
	virtual bool dial(const PhoneNumber &phoneNum) = 0;
	virtual bool speedDial(const int &index) = 0;
	virtual bool setSpeedDial(const int &index, const PhoneNumber &phoneNum) = 0;
};

class CordlessPhone
{
private:
	PhoneNumber PhoneNumber;
	str
public:
	CordlessPhone(/* args */);
	~CordlessPhone();
};

CordlessPhone::CordlessPhone(/* args */)
{
}

CordlessPhone::~CordlessPhone()
{
}
































































int main() {
    PersonalInfo per1(string("Jack"), string("Bauer"), string("5553425"), string("5553474"), string("5559835"),
                      string("jbauer@ctu.gov"));
    PersonalInfo per2(string("Jack"), string("Shepherd"), string("112"), string("112"), string("112"),
                      string("jack@lost.com"));
    PersonalInfo *people[] = {&per1, &per2};
    SIMCard simCard1(string("5550123"), people, 2), simCard2(string("5557755"));
    simCard2.add(per2);
    GsmPhone personalGsm(simCard1), businessGsm;
    businessGsm.insertCard(simCard1, simCard2);
    businessGsm.removeAllCards();
    businessGsm.insertCard(simCard2);
    FixedPhone homePhone(string("5552312"));
    homePhone.setSpeedDial(1, string("5556745"));
    CordlessPhone cordless1(string("5556621")), cordless2(string("5557843"), people, 2);
    cordless1.add(per1);

    CallableByName *cphone[] = {&personalGsm, &cordless1};
    for (int i = 0; i < 2; ++i)
        cphone[i]->dial(string("Jack"), string("Bauer"));
    Phone *phone[] = {&personalGsm, &cordless1, &homePhone};
    for (int i = 0; i < 3; ++i)
        phone[i]->dial(string("5552145"));
    for (int i = 0; i < 3; ++i)
        phone[i]->speedDial(1);
    SMSSendablePhone *smsPhone[] = {&personalGsm, &cordless1};
    smsPhone[0]->sms(string("5552145"), string("This is the message"));
    smsPhone[1]->sms(string("Jack"), string("Shephard"), string("Thank you for beating Benjamin"));
    Multimedia *mmData[] = {new Image("lena.jpg"), new Video("flight_815_crash.mp4")};
    MMSSendablePhone *mmsPhone[] = {&personalGsm, &businessGsm};
    mmsPhone[0]->mms(string("5552145"), mmData[0]);
    mmsPhone[1]->mms(string("Jack"), string("Shephard"), mmData[1]);
    return 0;
}