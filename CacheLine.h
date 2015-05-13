#ifndef CACHELINE_H
#define CACHELINE_H

class CacheLine
{
private:
	bool validity;
	int tag;
public:
	CacheLine();
	bool getValidity() const;
	int getTag() const;
	void setValidity(bool v);
	void setTag(int t);
};

#endif