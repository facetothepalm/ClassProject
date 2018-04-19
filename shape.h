#ifndef ERKK_SHAPE_H
#define ERKK_SHAPE_H
#include <iostream>

//* ABSTRACT SHAPE CLASS
//=======================

//	Notes:
//		- All singular coordinates apply to the top left
//			=> applies to: rectangle, square, ellipse, circle, text
//		- Consider adapting coord to QPoint instead
//		- Consider inheriting QPainter for shape (will allow draw and move functions inside class)
//			=> Downside however is huge overhead
//		- Consider a secondary abstract class for both actual shape/polygons (due to pen changes), and one for texts (due to text style changes)
//		- QPainter deals with coordinates and information of the object itself (IN REGARDS TO PEN & TEXT STYLING/CHANGES, it is beyond the scope of the shape class, invoked in paintEvent)
namespace ns_erkk_shape{
	struct coord;
	class shape;
}

struct coord{
	int x;
	int y;
};

class shape{
	protected:

	//*	CONSTRUCTOR/DESTRUCTOR
	//=========================
		//	May change type to an enum or int sort of like a flag
		//	Shape constructor (Allow derived shapes to handle array allocation)
		//	Protected to restrict abstract class constructor to user

		shape(string id, string type):id(id), type(type){}
		~shape();

	//*	DATA MEMBERS
	//======================

		int id;			//	Holds shape id 			NOTE: Need to check for uniqueness****
		string type; 	//	Holds shape type		NOTE: Leave type anyway for user awareness in case they're curious
		coord* loc;		//	Stores the elements into an array (various sizes due to the type of the shape)

	public:

	//*	ACCESSORS => These are all the same across all shapes in implementation
	//===========================

		virtual int getID()const = 0;							//	Returns id of shape
		virtual string getType()const = 0;						//	Returns type of shape
		virtual const coord* getLoc(int& arr_size)const = 0;	//	Returns const ptr of coord, accessed outside , passes size of array back in param


	//* MUTATORS => These are all the sae across all shapes in implementation
	//===========================

		virtual void setID(const int& input) = 0;				//	Returns void, changes id to user param arg
		virtual void setType(const string& input) = 0;			//	Returns void, changes type to user param arg
		virtual void setLoc(const coord* list) = 0; 			//	Returns void, adapts previous dimensions to list (ASSUMING list is same size)

	//*	FUNCTIONS 	(Will not be invoked unless inherits from QPainter)
	//==========================
	
		virtual void draw()const = 0;							//	Returns void, invokes QPainter draw based on shape type
		virtual void move(const coord new_loc) = 0;				//	Returns void, takes first coord of shape and moves it to that location [ADJUST REST OF VERTICES ALONG WAY]
		
};
#endif
