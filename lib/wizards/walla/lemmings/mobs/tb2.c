inherit "obj/monster";
#include <ansi.h>

int type;
int color;
int name;
string str2;
int vari;
int damitz;

reset(arg) {
    int i;
    int j;
    string str;
    int lvl;
    ::reset(arg);
    if (arg) return;
    i= random(5);
    if(i==0) str = "tiny";
    if(i==1) str = "small";
    if(i==2) str = "medium";
    if(i==3) str = "large";
    if(i==4) str = "HUGE";
    j= i;
    if(j==0) lvl = 19;
    if(j==1) lvl = 25;
    if(j==2) lvl = 30;
    if(j==3) lvl = 40;
    if(j==4) lvl = 48;
    damitz= i;
    if(i==0) damitz = 380;
    if(i==1) damitz = 500;
    if(i==2) damitz = 600;
    if(i==3) damitz = 800;
    if(i==4) damitz = 960;
    type= random(3);
    if(type==0) str2 = "cold";
    if(type==1) str2 = "fire";
    if(type==2) str2 = "electric";
    color= type;
    if(type==0) name = "white";
    if(type==1) name = "red";
    if(type==2) name = "blue";
    vari= type;
    if(type==0) vari = ""+BOLD+"";
    if(type==1) vari = ""+RED_F+"";
    if(type==2) vari = ""+BLUE_F+"";
 
    set_level(lvl+random(4));
    set_name("lemming");
    set_alias("bomber");
    set_short("A "+str+" "+name+" bomber lemming");
    set_long("The lemming is a small rodent, that has started standing on it's hind legs.\n"+
             "The lemming seems to have evolved into a very distinct population under the\n"+
             "mountains. They wear green pants and blue shirts, and live in huge colonies.\n");
    set_al(50);
    set_aggressive(1);
    set_gender(0);
    set_animal();
    set_special(100);

}


special_move() {
  object ob;

  ob = this_object()->query_attack();
  tell_object(ob, "Bomber lemming crouches into a ball and starts shaking. \n");
  tell_object(ob, "Bomber explodes into a "+vari+" "+name+" surge of power "+OFF+" that hits you in the face.\n");
  say("Bomber lemming crouches into a ball and explodes into a "+vari+" "+name+" surge of power "+OFF+" that hits "+ob->query_name()+" in the face. \n", ob);
  ob->hit_with_spell(damitz, ""+type+"");
  destruct(present("bomber",environment( this_object() )));

}

