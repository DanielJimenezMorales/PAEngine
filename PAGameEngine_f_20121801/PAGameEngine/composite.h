#pragma once
#include <vector>
#include "solid.h"
class Composite : public Solid{
	vector<Solid*> solids;
public:
	Composite() {}
	Composite(const Composite& c) : Solid(c) {
		for (Solid* ps : c.solids) {
			this->solids.push_back(ps->clone());
		}
	}
	virtual ~Composite(){
		for (Solid* ps : solids)
			delete ps;
		solids.clear();//No necesario, se llama automaticamente
	}
	Composite* clone() {
		return new Composite(*this);
	}
	vector<Solid*> getSolids() { return solids; }
	void setSolids(vector<Solid*> vs) { solids = vs; }
	Solid* getSolid(int i) {
		if (i >= solids.size() || i < 0)
			throw runtime_error("Out of range index, with value " + to_string(i) + " at Composite::getSolid()");
		return solids[i]; 
	}
	Solid* operator[](int i) {
		if (i >= solids.size() || i < 0)
			throw runtime_error("Out of range index, with value " + to_string(i) + " at Composite::getSolid()");
		return solids[i]; 
	}
	void add(Solid* ps) { solids.push_back(ps);}
	//
	void deleteAt(int pos) { solids.erase(solids.begin() + pos); }
	//
	void render();
	void update(double &dt);
	friend ostream& operator<<(ostream& os, const Composite& c);
};

