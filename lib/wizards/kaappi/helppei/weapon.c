* There is a generic weapon available. To set up do :
	object ob;
	ob = clone_object("obj/weapon");

* For customization the following routines are available.
* You should call these functions in the _following order_:


set_class(c)
    int c. Defines the quality of the weapon, affects total wc.
    Obligatory. c is between 1 and 9. c = monster_level / 10.
    !! Exception: 'club's do not have any class (they are wooden).

set_desc(str)
    string str. You can set a desc for the weapon, but it is not
    recommended for basic weapons. The desc is positioned as follows:
	A [str] steel short sword

set_sub_type(str)
    string str. See /doc/build/weapon_sub_types for available subtypes.
    Note that you must not set weight, wc, value or anything else than
    set_class(), if you use this function (except for maybe set_stats()).

set_slayer(str)
    string str. A race must be given as an argument (str). Gives a 50%
    chance of doing triple damage for each combat hit against a creature
    of defined race.

* Example as follows

inherit "obj/weapon";
start() {
  set_class(3);
  set_sub_type("broad axe");
}

* Only to be used in high class equipment from eq monsters:

set_stats(string stat, int bonus)
    Sets positive or negative stat modifiers to item.
    Multiple bonuses are possible.
    stat = [ str | dex | con | int | wis | hpr | spr | damage | hit ]
    bonus = [1-10]

* Note that short and long descriptions are normally automatically
* generated. You should first see the automatically generated descs before
* you set your own, so that you only change it a bit.

set_short(string short)
    Sets a short description for the weapon.

set_long(string long)
    Sets a long description for the weapon.

* If problems come up ask the adept or arch wizards.


						//Celtron
