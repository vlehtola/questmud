// CK_BLADE_D v0.5a

// DEFINES
#define BLADE_LEVEL(X)		ck_blade_data[X,0]
#define BLADE_QUALITY(X)	ck_blade_data[X,1]
#define BLADE_ALIGNMENT(X)	ck_blade_data[X,2]
#define BLADE_MATERIAL(X)	ck_blade_data[X,3]
#define BLADE_POINTS(X)		ck_blade_data[X,4]
#define BLADE_CORPSES(X)	ck_blade_data[X,5]
#define CK_FAITH(X)		ck_blade_data[X,6]


// VARS
static int blade_points, blade_corpses,blade_alignment, blade_level, ck_faith, blade_quality;
static string blade_material;
static object *blades = ({ });
mapping ck_blade_data = ([ ]);
static mapping materials = ([ ]);

// PROTOS
void reset_vars();
void count_blade_level(string name); // check
void count_blade_type(string name); // check
void count_blade_quality(string name); // check
void change_blade_material(string name, string material, object ob); //check
void add_blade_points(string name, int i); // check
void add_blade_corpses(string name, int i); // check
int query_blade_points(string name); // check
int query_blade_corpses(string name); // check
int query_blade_level(string name); // check
int query_blade_quality(string name); // check
int query_blade_alignment(string name); // check
void create_blade(string name); // check
void ck_update_sword(string name);
void restore_sword(string owner, object ob);
void ck_update_blade(string owner);
void save_data();

void reset() {
	reset_vars();
	// restore_object(CK_BLADE_DATA);
}
void count_blade_level(string name) {
	int i, temp;
	int bc, bp;
	
	bc = BLADE_CORPSES(name);
	bc *= 3; // 1 corpse is worth of 3 points
	bp = BLADE_POINTS(name);
	
	temp = bc + bp;
	switch(temp) {
		case 0..100 : 		i = 0; break;
		case 101..300 : 	i = 1; break;
		case 301..500 : 	i = 2; break;
		case 501..800 : 	i = 3; break;
		case 801..1200 :	i = 4; break;
		case 1201..1700 :	i = 5; break;
		case 1701..2400 :	i = 6; break;
		case 2401..3200 : 	i = 7; break;
		case 3201..4100 : 	i = 8; break;
		case 4101..5000 :	i = 9; break;
		case 5001..6000 :	i = 10; break;
		case 6001..7100 :	i = 11; break;
		case 7101..8300 : 	i = 12; break;
		case 8301..9600 :	i = 13; break;
		case 9601..10000 :	i = 14; break;
		case 10001..11500 :	i = 15; break;
		case 11501..20000 :	i = 16; break;
		default : 		i = 17;  break; // > 20000
	}
	BLADE_LEVEL(name) = i;
}

string get_blade_type(string name) {
	int i;
	if(!name)return "";
	count_blade_level(name);
	i = BLADE_LEVEL(name);
	
	switch(i) {
			case 0 : return "dagger"; break;
			case 1 : return "main gauche"; break;
			case 2 : return "dirk"; break;
			case 3 : return "rapier"; break;
			case 4 : return "poker";break;
			case 5 : return "foil";break;
			case 6 : return "sai";break;
			case 7 : return "short sword"; break;
			case 8 : return "scimitar"; break;
			case 9 : return "cutlass"; break;
			case 10 : return "sabre"; break;
			case 11 : return "longsword"; break;
			case 12 : return "falchion"; break;
			case 13 : return "bastard sword"; break;
			case 14 : return "claymore"; break;
			case 15 : return "great sword"; break;
			case 16 : return "death blade"; break;
			case 17 : return "chaos blade"; break;
}

}

void change_blade_material(string name, string mat, object ob) {
	string temp;
	
	if(!materials[mat]) {
		BLADE_MATERIAL(name) = "steel";
		ob->set_material("steel","physical",1);
	}
	else temp = mat;
	
	BLADE_MATERIAL(name) = temp;
	
	ob->set_blade_material(temp,materials[temp,0],materials[temp,1]);
	
}
 


void count_blade_quality(string name) {
	
	int i, temp;
	int ckf, ba;
	
	ckf = CK_FAITH(name) / 20; // CKF 0-100
	ba = BLADE_ALIGNMENT(name) / 20; // BA 0-100
	temp = ckf+ba;
	if(temp < 0) temp = 0;
	if(temp > 10) temp = 10;	
	BLADE_QUALITY(name) = temp;
}

string get_blade_quality(string name) {
	count_blade_quality(name);
	
	switch(BLADE_QUALITY(name)) {
		case 0 : return "mean looking"; break;
		case 1 : return "curved"; break;
		case 2 : return "wickedly curved"; break;
		case 3 : return "sardonic"; break;
		case 4 : return "spleeny"; break;
		case 5 : return "vituperative"; break;
		case 6 : return "malignant"; break;
		case 7 : return "malicious"; break;
		case 8 : return "malevolent"; break;
		case 9 : return "venomous"; break;
		case 10 : return "chaotic"; break;
}

}

void create_blade(string name) {
	object ob;
	
	reset_vars();
	if(!name)return;
	if(!ck_blade_data[name]) {
		ck_blade_data += ([ name : blade_level; blade_quality; blade_alignment; blade_material; blade_points; blade_corpses; ck_faith, ]);
	}
	blades += ({ ob });
	/*
	ob = clone_object(CK_BLADE);
	ob -> set_owner(name);
		
	*/
	
}
		
void reset_vars() {
	blade_points = 0;
	blade_corpses = 0;
	blade_level = 0;
	blade_quality = 0;
	ck_faith = 0;
	blade_material = "steel";
	blade_alignment = 0;
			// material : damage_type, damage-percent.
	materials = ([ "uranium" : "poison" ; 50,
	               "pikadium" : "electric" ; 50,
	               "zinconium" : "cold" ; 50,
	               "moronium" : "fire" ; 50,
	               "raginium" : "adic" ; 50,
	               "pappidium" : "psionic" ; 50,
	               "zippadium" : "asphyxiation"; 50,
	              ]);	
}


void add_blade_points(string name, int i) {
	BLADE_POINTS(name) += i;
}
void add_blade_corpses(string name, int i) {
	BLADE_CORPSES(name) += i;
}
void add_blade_alignment(string name, int i) {
	BLADE_ALIGNMENT(name) += i;
}
void add_ck_faith(string name, int i) {
	CK_FAITH += i;
}

int query_ck_faith(string name) {
	return CK_FAITH(name);
}

mapping query_data() {
	return ck_blade_data;
}

int query_blade_alignment(string name) {
	return BLADE_ALIGNMENT(name);
}

int query_blade_points(string name) {
	return BLADE_POINTS(name);
}
int query_blade_corpses(string name) {
	return BLADE_CORPSES(name);
}
int query_blade_level(string name) {
	return BLADE_LEVEL(name);
}

int query_blade_quality(string name) {
	return BLADE_QUALITY(name);
}

int query_blade_material(string name) {
	return BLADE_MATERIAL(name);
}
