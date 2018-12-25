class myKid
{
public:
	std::string m_name;
	int m_age;

	myKid() :
		m_name(""),
		m_age(0)
	{}

	myKid(std::string name, int age) :
		m_name(name),
		m_age(age)
	{}

	myKid(myKid& other) : 
		m_name(other.m_name),
		m_age(other.m_age)
	{}

	~myKid()
	{}

	myKid& operator = (myKid& other)
	{
		m_name = other.m_name;
		m_age = other.m_age;

		return *this;
	}

	int& getAge() { return m_age; }
	void setAge(int age) { m_age = age; }

	std::string getName() { return m_name; }

	void printInfo()
	{
		std:: cout << "        Name: " << m_name << ", age: " << m_age << std::endl;
	}
};