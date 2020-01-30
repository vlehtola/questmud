// CK's Blade v0.5a

/*	TODO: (after CK_BLADE_D is ready)
		* Full support for CK_BLADE_D
		* Working update-system.
		* Blade specials
			<> exp-draining
			<> blade-alignment
		
*/

#define OWNER find_player(blade_owner)
#define CK_BLADE_D "/wizards/astarel/ck/daemons/ck_blade_d.c"
#define BLADE_WC 10 // blade_level * BLADE_WC = class_of_weapon. now its 1 - 170

// VARS
int blade_level, blade_points, blade_alignment, blade_damage_amount;
string blade_owner, blade_quality, blade_type, blade_material, blade_damage_type;

inherit "obj/weapon";

// PROTOS
void update_blade();
status blade_handling_function(string str);
status blade_drain(string str);
status blade_sacrifice(string str);
status blade_donate();
void blade_help(string str);

void set_blade_owner(string str) {
	blade_owner = str;
}
void set_blade_level(int i) {
	blade_level = i;
}

void set_blade_material(string str,string dam_type, int amount) {
	blade_material = str;
	blade_damage_type = dam_type;
	blade_damage_amount = amount;
}
void set_blade_type(string str) {
	blade_type = str;
}
void set_blade_quality(string str) {
	blade_quality = str;
}

void set_blade_alignment(int i) {
	blade_alignment = i;
}

string query_blade_owner() {
	return blade_owner;
}
int query_blade_level(int i) {
	return blade_level;
}
string query_blade_material() {
	return blade_material;
}
string query_blade_type() {
	return blade_type;
}
string query_blade_quality() {
	return blade_quality;
}
int query_blade_alignment() {
	return blade_alignment;
}

/********** CODE ***********/
void start(status arg) {
	
	//if(arg)return;
	
	set_class(9);
	set_sub_type("long sword");
	
	blade_level = 0;
	blade_points = 0;
	blade_alignment = 0;
	
	max_dur = 10000;
	dur = 10000;
	
	blade_type = "great sword";
	blade_material = "Adamantium";
	blade_quality = "chaotic";
	
	blade_damage_type = "physical";
	blade_damage_amount = 1;
	
	blade_owner = "astarel";
	
	name = "chaos blade";
	alias = "blade";
	
	short_desc = capitalize(blade_owner)+"'s "+blade_quality+" "+blade_material+" "+blade_type+" <humming>";
	long_desc = "TO\n";

	class_of_weapon = 100;
	
	value = 0;
	weight = 100;	
	
	// CK_D->restore_sword(owner);
	
}

init() {
	::init();
	add_action("blade_handling_function","blade");
	
}

status blade_handling_function(string str) {
	
	string *temp;
	int i;
	
	if(!str) {
		write("Usage: type 'blade help' to get information how this crap works.\n");
		return 1;
	}
	
	temp = explode(str," ");
	
	write("SIZEOF temp: "+sizeof(temp)+"\n");
	
	
		for(i = sizeof(temp) ; i < 5; i++) {
			temp += ({ "" });
			
		}
	
	write("SIZEOF temp: "+sizeof(temp)+"\n");
	
	switch(temp[0]) {
		
		case "help" : blade_help(temp[1]); return 1;
		case "drain" : blade_drain(temp[1]); return 1;
		case "donate" : blade_donate(); return 1;
		case "sacrifice" : blade_sacrifice(temp[1]); return 1;
		default : write("Usage: blade <command>, type 'blade help' to get list of commands\n"); return 1;
	}
	
}

void blade_help(string str) {
	
	if(!str || str == "") {
	write(".---------------------------------------.\n"+
	      "|    The omnipotentious Chaos blade     |\n"+
	      "'---------------------------------------'\n"+
	      "| Commands:   Info                      |\n"+
	      "| help        This help. blade help <>  |\n"+
	      "| drain	     Drains corpse.	       |\n"+
	      "| sacrifice   Sacrifices corpse.        |\n"+
	      "| donate      Donates all drained powers|\n"+
	      "'---------------------------------------'\n");
	}
	
	switch(str) {
		case "help" : write("Are you stupid or what?!\n"); break;
		case "drain" : write("Usage: blade drain <corpse>\n"+
		                     "drains the powers of corpse into your blade making it more powerful.\n");
		                     break;
		case "sacrifice" : write("Usage: blade sacrifice <corpse>\n"+
					 "sacrifices the powers of the corpse to dark god Taels'Ar making it more pleased to you.\n");
					 break;
		case "donate" :	   write("Usage: blade donate\n"+
		                         "Donates the swords powers to dark god Taels'Ar. Similar affects with 'sacrifice'\n");
		                         break;
		default : write("dont even bother.\n");break;
	}
	
}

status blade_drain(string str) {
	
	int i;
	object ob;
	
	if(!present(str,environment(OWNER))) {
		write("No such thing here.\n");
		return 1;
	}
	
	ob = present(str,environment(OWNER));
	
	if(!ob) {
		write("BUG!\n");
	}
	
	if(!ob->query_corpse()) {
		write(capitalize(ob->query_name())+" is not a corpse!\n");
	}
	
	if(ob->query_corpse()) {
		
		write("You turn your "+short()+" towards the "+ob->short()+".\n"+
		      "You chant 'Uo ka dio meeh' and with one swift move you pierce\n"+
		      ob->short()+" lifeless body. "+short()+" starts emitting\n"+
		      "dark, chaotical light and corpse slowly vanishes.\n"+
		      "You feel how pleased the dark god Taels'Ar is.\n");
		
		i = ob->query_level() / 10;
		if(i < 1)i = 1;
		blade_points += i;
				
		CK_BLADE_D->add_blade_corpses(blade_owner,1);
		
		write("Your lovely blade has consumed corpses and gathered "+blade_points+" points.\n");
		
		
		destruct(ob);
		return 1;
	}
	
	write("Something bugged\n");
	return 1;
}

status blade_sacrifice(string str) {
	
	int i;
	object ob;
	
	if(!present(str,environment(OWNER))) {
		write("No such thing here.\n");
		return 1;
	}
	
	ob = present(str,environment(OWNER));
	
	if(!ob) {
		write("BUG!\n");
	}
	
	if(!ob->query_corpse()) {
		write(capitalize(ob->query_name())+" is not a corpse!\n");
	}
	
	if(ob->query_corpse()) {
		
		write("You kneel in front of "+ob->short()+" intoning a silent prayer.\n"+
		      "Dark presence fills the room, making your spirit bathe in ecstasy.\n"+
		      "Your "+short()+" starts emitting a dark fog which quickly drowns the corpse\n"+
		      "making it slowly disappear.\n"+
		      "You feel how grateful Taels'Ar is from your sacrifice.\n");
		
		i = ob->query_level() / 10;
		if(i < 1)i = 1;
		CK_BLADE_D->add_blade_points(blade_owner,i);
		CK_BLADE_D->add_blade_corpses(blade_owner,i);
		
		write("Your lovely blade has consumed corpses and gathered "+blade_points+" points.\n");
		
		
		destruct(ob);
		return 1;
	}
	
	write("Something bugged\n");
	return 1;
}

void blade_donate() {
	write("You raise your blade above your head, kneel down and whisper 'Ai ge lau di Taels'Ar ha do'\n"+
	      "Your blade glows brightly for a while, then it dims and looks much less powerful than before.\n");
	
	write("You hear a godly voice echoing in your head 'I'm pleased\n'");
	
	CK_BLADE_D->add_blade_points(name,blade_points);
	blade_points = 0;
	
}

void blade_update() {
	
	set_blade_alignment(CK_BLADE_D->query_blade_alignment(blade_owner));
	
	CK_BLADE_D->count_blade_level(blade_owner);
	set_blade_level(CK_BLADE_D->query_blade_level(blade_owner));
	
	class_of_weapon = blade_level * BLADE_WC;
	if(class_of_weapon < 0)class_of_weapon = 1;
	
	CK_BLADE_D->change_blade_material(blade_owner, CK_BLADE_D->query_blade_material(), this_object());
		
	set_blade_quality(CK_BLADE_D->get_blade_quality(blade_owner));
	
	set_blade_type(CK_BLADE_D->get_blade_type(blade_owner));
	
	set_short(capitalize(blade_owner)+"'s "+blade_quality+" "+blade_material+" "+blade_type+" "+blade_damage_type);
	set_name(blade_type);
	
}

