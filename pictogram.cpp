#include <iostream>
#include <cctype>
#include <string>
using namespace std;

class User
{
protected:
    string username, email, password;

public:
    User() : username(""), email(""), password("") {}
    void setUserName(string username)
    {
        this->username = username;
    }
    void setEmail(string email)
    {
        this->email = email;
    }
    void setPassword(string password)
    {
        this->password = password;
    }
    void caesarEncrypt()
    {
        string encryptedText;
        int textLength = static_cast<int>(password.length());

        for (int i = 0; i < textLength; ++i)
        {
            int shift = 3;
            char c = password[i];
            if (isalpha(c))
            {
                char base = isupper(c) ? 'A' : 'a';
                encryptedText += static_cast<char>(((c - base + shift) % 26) + base);
            }
            else
            {
                encryptedText += c;
            }
        }

        password = encryptedText;
    }

    string getEncryptedPassword() const
    {
        return password;
    }
    string getUsername()
    {
        return username;
    }
    string getEmail()
    {
        return email;
    }
};

class Post
{
    string postId;
    int likes = 0;
    int views = 0;
    string content;
    string *comments;

    int commentsnum = 0;

public:
    Post()
    {
        comments = new string[100];
    }
    void setId(string postId)
    {
        this->postId = postId;
    }
    void addLikes()
    {
        likes++;
    }
    void addViews()
    {
        views++;
    }
    int getLikes()
    {
        return likes;
    }
    int getViews()
    {
        return views;
    }
    int getCommentsNum()
    {
        return commentsnum;
    }
    void addComments(string comment)
    {
        comments[commentsnum] = comment;
        commentsnum++;
    }
    void setContent(string content)
    {
        this->content = content;
    }
    void display()
    {
        cout << "Likes: " << likes << endl;
        cout << "Comments: " << commentsnum << endl;

        for (int i = 0; i < commentsnum; i++)
        {
            cout << comments[i] << endl;
        }
    }
    string getId()
    {
        return postId;
    }
    string getContent()
    {
        return content;
    }
};

int postCount = 0;
class Business;
class Regular : public User
{
    static Post *feed;
    static const int MAX_FEED_SIZE = 10;
    friend class Business;

public:
    static int countfeed;

    Regular() : User()
    {
        feed = new Post[MAX_FEED_SIZE];
    }
    void addPosts()
    {
         countfeed++;
        if (countfeed > 10)
        {
            cout << "Server Crashhh:(" << endl;
            return;
        }    
        postCount++;

        if (postCount > 5)
        {
            cout << "You are Regular User you can add only 5 posts and you have reached your limit" << endl;
        }
        else
        {
            cout << "Describe your Post" << endl;
            cout << "content: ";
            string content;
            getline(cin, content);
            feed[postCount-1].setContent(content);
            feed[postCount-1].setId(username);

    
        }
    }
    void display()
    {
        for (int i = 0; i < postCount; i++)
        {
            cout << "Posted by: " << feed[i].getId() << "    content: " << feed[i].getContent() << endl;
            feed[i].display();
        }
    }
    void forYou()
    {
        for (int i = 0; i < postCount; i++)
        {
            cout << "Posted by: " << feed[i].getId() << "    content: " << feed[i].getContent() << endl;
            feed[i].display();
            char choice;
            cout << "Do you want to like this post? (y/n)/(Y/N): ";
            cin >> choice;
            cin.ignore();
            if (choice == 'y' || choice == 'Y')
            {
                feed[i].addLikes();
            }
            cout << "Do you want to comment on this post? (y/n), (Y/N): ";
            cin >> choice;
            cin.ignore();
            if (choice == 'y' || choice == 'Y')
            {
                cout << "Enter the comment: ";
                string comm;
                getline(cin, comm);
                feed[i].addComments(comm);
            }
            cout << endl
                 << endl;
        }
    }
};
Post *Regular::feed;
class Business : public User
{
public:
    void promote()
    {
        int count = 0;
        if (count > 10)
        {
            cout << "You have reached your limit :(" << endl;
            return;
        }
        char choice;
        for (int i = 0; i < postCount; i++)
        {
            Regular::feed[i].display();
            cout << "Do You want to promote this post?(y/n), (Y/N): ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                Regular::feed[i].addLikes();
                Regular::feed[i].addLikes();
                Regular::feed[i].addViews();
                Regular::feed[i].addViews();
                Regular::feed[i].addViews();
            }
        }
        std::cout << "\033[1;34mANALYTICS\033[0m" << endl;
        for (int i = 0; i < postCount; i++)
        {
            Regular::feed[i].display() ;
            cout << "  Views: " <<  Regular::feed[i].getViews() << endl;
        }
    }
};
int Regular::countfeed = 0;
int main()
{
    string name, emailid, password;
    Regular regusers[3];
    int choice;
    for (int i = 0; i < 3; i++)
    {
        cout << "\033[1;31mP I C T O G R A M\033[0m" << endl;
        cout << "Sign up (Regular User)!!!" << endl;
        cout << "Enter your name: ";
        getline(cin, name);
        cout << "Enter you email id: ";
        getline(cin, emailid);
        cout << "Enter the password: ";
        getline(cin, password);
        regusers[i].setUserName(name);
        regusers[i].setPassword(password);
        regusers[i].setEmail(emailid);
        while (1)
        {
            cout << "1.add post" << endl
                 << "2.view your posts" << endl
                 << "3.for you page" << endl
                 << "4.exit" << endl;
            cout << "Enter the choice: ";
            cin >> choice;
            cin.ignore();
            switch (choice)
            {
            case 1:
                regusers[i].addPosts();
                break;
            case 2:
                std::cout << "\033[1;34mYOUR FEED\033[0m" << endl;
                cout << "\033[1;34m---------------------------\033[0m" << endl;
                regusers[i].display();
                cout << "\033[1;34m---------------------------\033[0m" << endl;
                break;
            case 3:
                cout << "\033[1;32mFOR YOU PAGE\033[0m" << endl;
                cout << "\033[1;32m---------------------------\033[0m" << endl;
                regusers[i].forYou();
                cout << "\033[1;32m---------------------------\033[0m" << endl;
                break;
            case 4:
                break;
            default:
                cout << "Ivalid info" << endl;
                continue;
            }
            if (choice == 4)
                break;
        }
    }
    Business b;
    b.promote();
    return 0;
}