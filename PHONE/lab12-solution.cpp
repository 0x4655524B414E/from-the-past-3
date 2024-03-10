#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
typedef string PhoneNumber;
typedef string EMail;
typedef string TextMessage;

class PersonalInfo {
private:
    string firstName;
    string lastName;
    PhoneNumber homePhoneNumber;
    PhoneNumber gsmPhoneNumber;
    PhoneNumber businessPhoneNumber;
    EMail email;
public:
    PersonalInfo(string first, string last, PhoneNumber home, PhoneNumber gsm, PhoneNumber business, EMail e_mail) {
        firstName = first;
        lastName = last;
        homePhoneNumber = home;
        gsmPhoneNumber = gsm;
        businessPhoneNumber = business;
        email = e_mail;
    }

    bool operator()(string, string) const;

    PhoneNumber getHomePhoneNumber() const;

    PhoneNumber getGsmPhoneNumber() const;

    PhoneNumber getBusinessPhoneNumber() const;

    string getFirstName() const;

    void setHomePhoneNumber(PhoneNumber);

    void setGsmPhoneNumber(PhoneNumber);

    void setBusinessPhoneNumber(PhoneNumber);
};

PhoneNumber PersonalInfo::getHomePhoneNumber() const {
    return homePhoneNumber;
}

string PersonalInfo::getFirstName() const {
    return firstName;
}

bool PersonalInfo::operator()(string first, string last) const {
    return (firstName == first) && (lastName == last);
}


class Phone {
public:
    virtual bool dial(PhoneNumber) = 0;

    virtual bool setSpeedDial(int, PhoneNumber) = 0;

    virtual bool speedDial(int) = 0;
};

class CallableByName {
public:
    virtual bool dial(string, string) = 0;

    virtual bool add(PersonalInfo &) = 0;
};

class SMSSendablePhone {
public:
    virtual bool sms(PhoneNumber, const TextMessage &) = 0;

    virtual bool sms(string, string, const TextMessage &) = 0;
};

class Multimedia {
public:
};

class Image : public Multimedia {
public:
    Image(char *) {}
};

class Video : public Multimedia {
public:
    Video(char *) {}
};

class MMSSendablePhone {
public:
    virtual bool mms(PhoneNumber, Multimedia *) = 0;

    virtual bool mms(string, string, Multimedia *) = 0;
};

class SIMCard {
private:
    PhoneNumber phoneNumber;
protected:
    vector<PersonalInfo> phoneBook;
public:
    SIMCard(PhoneNumber phone_number) : phoneNumber(phone_number) {}

    SIMCard(PhoneNumber phone_number, PersonalInfo **info, int length) : phoneNumber(phone_number) {
        for (int i = 0; i < length; ++i)
            phoneBook.insert(phoneBook.end(), *info[i]);
    }

    bool add(PersonalInfo &inf) {
        phoneBook.insert(phoneBook.end(), inf);
    }

    PhoneNumber getPhoneNumber() const { return phoneNumber; }

    vector<PersonalInfo> *getPhoneBook();
};

vector<PersonalInfo> *SIMCard::getPhoneBook() {
    return &phoneBook;
}

class GsmPhone : public Phone, public CallableByName, public SMSSendablePhone, public MMSSendablePhone {
private:
    SIMCard *simCard[2];
    int numberOfSIMCardAvailable;
    map<int, string> speedDialKeys;
public :
    GsmPhone() {
        numberOfSIMCardAvailable = 0;
    }

    GsmPhone(SIMCard &sim) {
        simCard[0] = &sim;
        numberOfSIMCardAvailable = 1;
    }

    bool insertCard(SIMCard &sim) {
        if (numberOfSIMCardAvailable > 2) return false;
        simCard[numberOfSIMCardAvailable++] = &sim;
        return true;
    }

    bool insertCard(SIMCard &sim1, SIMCard &sim2) {
        if (numberOfSIMCardAvailable > 0) return false;
        simCard[numberOfSIMCardAvailable++] = &sim1;
        simCard[numberOfSIMCardAvailable++] = &sim2;
        return true;
    }

    void removeAllCards() {
        numberOfSIMCardAvailable = 0;
    }

    bool dial(PhoneNumber phoneNumber) {
        if (phoneNumber == string("155")) {
            cout << "Making emergency call to 155" << endl;
            return true;
        }
        if (numberOfSIMCardAvailable == 0) return false;
        cout << simCard[0]->getPhoneNumber() << " is calling to " << phoneNumber << endl;
        return true;
    }

    bool dial(string first, string last) {
        if (numberOfSIMCardAvailable == 0)
            return false;
        if (numberOfSIMCardAvailable == 0) return false;
        vector<PersonalInfo> *phoneBook = simCard[0]->getPhoneBook();
        PhoneNumber phone_number;
        bool found = false;
        vector<PersonalInfo>::iterator iter = phoneBook->begin();
        while (iter != phoneBook->end()) {
            PersonalInfo inf = *iter;
            if (inf(first, last)) {
                phone_number = inf.getHomePhoneNumber();
                found = true;
                break;
            }
            ++iter;
        }
        if (found) {
            cout << simCard[0]->getPhoneNumber() << " is calling to " << phone_number << endl;
        }
        return found;
    }

    bool add(PersonalInfo &person) {
        if (numberOfSIMCardAvailable == 0) return false;
        simCard[0]->add(person);
    }

    bool sms(PhoneNumber phone_number, const TextMessage &msg) {
        if (numberOfSIMCardAvailable == 0) return false;
        cout << simCard[0]->getPhoneNumber() << " is sending sms to " << phone_number << endl;
        cout << "Message: " << msg << endl;
    }

    bool sms(string first, string last, const TextMessage &msg) {
        if (numberOfSIMCardAvailable == 0) return false;
        vector<PersonalInfo> *phoneBook = simCard[0]->getPhoneBook();
        PhoneNumber phone_number;
        bool found = false;
        vector<PersonalInfo>::iterator iter = phoneBook->begin();
        while (iter != phoneBook->end()) {
            PersonalInfo inf = *iter;
            if (inf(first, last)) {
                phone_number = inf.getHomePhoneNumber();
                found = true;
                break;
            }
            ++iter;
        }
        if (found) {
            cout << simCard[0]->getPhoneNumber() << " is sending sms to " << phone_number << endl;
            cout << "Message: " << msg << endl;
        }
        return found;
    }

    bool mms(PhoneNumber phoneNumber, Multimedia *msg) {
        cout << simCard[0]->getPhoneNumber() << " is sending mms to " << phoneNumber << endl;
        return true;
    }

    bool mms(string first, string last, Multimedia *msg) {
        if (numberOfSIMCardAvailable == 0) return false;
        vector<PersonalInfo> *phoneBook = simCard[0]->getPhoneBook();
        PhoneNumber phone_number;
        bool found = false;
        vector<PersonalInfo>::iterator iter = phoneBook->begin();
        while (iter != phoneBook->end()) {
            PersonalInfo inf = *iter;
            if (inf(first, last)) {
                phone_number = inf.getHomePhoneNumber();
                found = true;
                break;
            }
            iter++;
        }
        if (found) {
            cout << simCard[0]->getPhoneNumber() << " is sending mms to " << phone_number << endl;
            cout << "Message: " << msg << endl;
        }
        return found;
    }

    bool setSpeedDial(int key, PhoneNumber phone_number) {
        pair<int, string> speed_key(key, phone_number);
        speedDialKeys.insert(speedDialKeys.end(), speed_key);
        return true;
    }

    bool speedDial(int key) {
        map<int, string>::iterator iter = speedDialKeys.find(key);
        if (iter == speedDialKeys.end()) return false;
        cout << simCard[0]->getPhoneNumber() << " is calling to " << (*iter).second << endl;
    }
};

class CordlessPhone : public Phone, public CallableByName, public SMSSendablePhone {
private:
    PhoneNumber phoneNumber;
    map<int, string> speedDialKeys;
    vector<PersonalInfo> phoneBook;
public :
    CordlessPhone(PhoneNumber phone_number, PersonalInfo **info, int length) : phoneNumber(phone_number) {
        for (int i = 0; i < length; ++i)
            phoneBook.insert(phoneBook.end(), *info[i]);
    }

    CordlessPhone(PhoneNumber phone_number) : phoneNumber(phone_number) {
        phoneBook.clear();
    }

    bool dial(PhoneNumber phone_number) {
        cout << phoneNumber << " is calling to " << phone_number << endl;
    }

    bool dial(string first, string last) {
        PhoneNumber phone_number;
        bool found = false;
        vector<PersonalInfo>::iterator iter = phoneBook.begin();
        while (iter != phoneBook.end()) {
            PersonalInfo inf = *iter;
            if (inf(first, last)) {
                phone_number = inf.getHomePhoneNumber();
                found = true;
                break;
            }
            iter++;
        }
        if (found)
            cout << phoneNumber << " is calling to " << phone_number << endl;
        return found;
    }

    bool add(PersonalInfo &person) {
        phoneBook.insert(phoneBook.begin(), person);
    }

    bool sms(PhoneNumber phone_number, const TextMessage &msg) {
        cout << phoneNumber << " is sending sms to " << phone_number << endl;
        cout << "Message: " << msg << endl;
    }

    bool sms(string first, string last, const TextMessage &msg) {
        PhoneNumber phone_number;
        bool found = false;
        if (phoneBook.empty()) return false;
        vector<PersonalInfo>::iterator iter = phoneBook.begin();
        while (iter != phoneBook.end()) {
            PersonalInfo inf = *iter;
            if (inf(first, last)) {
                phone_number = inf.getHomePhoneNumber();
                found = true;
                break;
            }
            iter++;
        }
        if (found) {
            cout << phoneNumber << " is sending sms to " << phone_number << endl;
            cout << "Message: " << msg << endl;
        }
        return found;
    }

    bool setSpeedDial(int key, PhoneNumber phone_number) {
        pair<int, string> speed_key(key, phone_number);
        speedDialKeys.insert(speedDialKeys.end(), speed_key);
        return true;
    }

    bool speedDial(int key) {
        map<int, string>::iterator iter = speedDialKeys.find(key);
        if (iter == speedDialKeys.end()) return false;
        cout << phoneNumber << " is calling to " << (*iter).second << endl;
    }

};

class FixedPhone : public Phone {
private:
    map<int, string> speedDialKeys;
    PhoneNumber phoneNumber;
public :
    FixedPhone(PhoneNumber phone_number) : phoneNumber(phone_number) {
    }

    bool dial(PhoneNumber phone_number) {
        cout << phoneNumber << " is calling to " << phone_number << endl;
    }

    bool setSpeedDial(int key, PhoneNumber phone_number) {
        pair<int, string> speed_key(key, phone_number);
        speedDialKeys.insert(speedDialKeys.end(), speed_key);
        return true;
    }

    bool speedDial(int key) {
        map<int, string>::iterator iter = speedDialKeys.find(key);
        if (iter == speedDialKeys.end()) return false;
        cout << phoneNumber << " is calling to " << (*iter).second << endl;
    }
};

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