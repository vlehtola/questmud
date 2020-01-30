// Sorcerer's staff. (guilditem) Responsibility of Moonstar.

#include <ansi.h>

#define SAVE_DIR 	"/data/sorcerer/staff/"
#define TP		this_player()

inherit "obj/weapon";

int staff_points; 	// Descriptive variable names
string owner_name;
drop() { return 1; }
start()
{
 set_class(100);
 set_sub_type("club");
 set_name("sor_staff");
 set_alias("staff");
 set_short(""+BLUE_F+"The blue staff of Sorcerers"+OFF+"");
 set_long("Sorcerers blue staff. kirjota pitempi desci. mainitse runeista\n"+
          "Kissa juoksee\n");

 if( TP->query_skills("faith of izyldran") / 10)
   set_stats("wis", ( TP->query_skills("faith of izyldran")/10) );

 if( TP->query_skills("mind link")/10 )
   set_stats("int", ( TP->query_skills("mind link")/10) );

 if( TP->query_skills("knowledge of power")/10 )
    set_stats("spr", ( TP->query_skills("knowledge of power")/10) );

 if(!owner_name) owner_name = TP->query_real_name();

 // Aina kun tama esine clonetaan, haetaan vanha data tiedostosta:
 if(owner_name)
    restore_object( SAVE_DIR+owner_name );
 if(!staff_points) staff_points = 0;
}

init() 
{
 ::init();
 add_action("read", "read");
 add_action("drain", "drain");
}

read(string str) 
{
  if(str != "runes") return 0;
  write("The runes say something about draining the dead souls with the staff.\n");
  write("You have "+staff_points+" soul points in your staff. Staffin rankki on:"+get_short(staff_points)+"\n");
  return 1;
}

drain(string str) 
{
 object ob;

 if(str != "corpse") return 0;
 if(!wielded_by) return 0;

 ob = present("corpse", environment(this_player()));

 if(!ob) {
    write("The staff burns your hand!\n");
    wielded_by->hit_with_spell(random(150), "physical");
    return 1;
   }

 if(!ob->query_corpse()) {
     write("Words of some unknown language echo within your head.\n");
     return 1;
    }

 staff_points += (ob->query_level());
 write("You place the staff above the corpse and drain the soul out from it.\n");
 say(wielded_by->query_name()+" places a staff above the corpse and en ethereal shape rises out from the corpse.\n");
 destruct(ob);
 // Aina kun mosa drainitaan, tallennetaan uudet arvot datafiluun
 save_object(SAVE_DIR+wielded_by->query_real_name());
return 1;
}

get_short(int staff_points) {
  switch(staff_points)
	{
         case 0..300: return ""+BLUE_F+"<Child of Izyldran>"+OFF+"";
         case 301..800: return ""+BLUE_F+"<Worshipper of Izyldran>"+OFF+"";
         case 801..1400: return ""+BLUE_F+"<Apprentice priest of Izyldran>"+OFF+"";
         case 1401..3000: return ""+BLUE_F+"<Preacher priest of Izyldran>"+OFF+"";
         case 3001..5000: return ""+BLUE_F+"<Priest of Izyldran>"+OFF+"";
         case 5001..10000: return ""+BLUE_F+"<Cardinal of Izyldran>"+OFF+"";
         case 10001..20000: return ""+RED_F+"<Highsorcerer of Izyldran>"+OFF+"";
         case 20001..35000: return ""+RED_F+"<Master sorcerer of Izyldran>"+OFF+"";
         case 35001..70000: return ""+BLUE_F+"<Supreme sorcerer of Izyldran>"+OFF+"";
         case 70001..120000: return ""+BLUE_F+"<Adept sorcerer of Izyldran>"+OFF+"";
         case 120001..250000: return ""+RED_F+"<Grandsorcerer of Izyldran>"+OFF+"";
         case 250001..500000: return ""+RED_F+"<Archsorcerer of izyldran>"+OFF+"";
        }
  return ""+RED_F+"<Elder sorcerer>"+OFF+"";
}

check_weapon_break() { return 1; }

