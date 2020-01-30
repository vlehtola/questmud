//normal bows; elven bow, orcish bow, composite bow, war bow, compound, recurve
//also short and long version of those, like short composite bow tms

//Crossbows: hand crossbow, light crossbow, crossbow, heavy crossbow, pellet crossbow,
#define BOW_FILE "/wizards/siki/bow"
#define ARROW_FILE "/wizards/siki/arrow"

#define ARROW_NAME 0
#define ARROW_DAMAGE 1
#define ARROW_HIT 2
#define ARROW_CRIT 3
#define ARROW_STUN 4
#define ARROW_WEIGHT 5
#define ARROW_TYPE 6

// name, bdamage, bhit, size, reloadtime, shootime, weight, type
#define BOW_NAME 0
#define BOW_BDAMAGE 1
#define BOW_BHIT 2
#define BOW_SIZE 3
#define BOW_RTIME 4
#define BOW_STIME 5
#define BOW_WEIGHT 6
#define BOW_TYPE 7

int array_crossbows;
int array_bows;

mixed *bows;
mixed *crossbows;

mixed *arrows;
mixed *bolts;

query_bolts() { return ({ "flight bolt", "broadhead bolt", "bodkin bolt", "forked bolt", "blunt bolt", }); }
query_crossbows() { return ({ "light crossbow", "heavy crossbow", }); }

create() {
// name, bdamage, bhit, size, reloadtime, shootime, weight, type
	crossbows = ({
	"light crossbow", 25, 50, 30, 4, 5, 500, "bolt",
	"heavy crossbow", 50, 25, 60, 6, 10, 2500, "bolt",
});
/// name, damage, hit, crit, stun, weight, type,
bolts = ({
	"flight bolt", 10, 50, 10, 10, 1,"bolt",
	"broadhead bolt", 20, 40, 20, 30, 1, "bolt",
	"bodkin bolt", 40, 40, 20, 30, 1, "bolt",
	"forked bolt", 50, 30, 30, 40, 1, "bolt",
	"blunt bolt", 30, 10, 20, 50, 1, "bolt",
});

array_crossbows=sizeof(crossbows);
/*
bows = ({
	"short bow", 3, 3, 2, 350, "arrow",
	"long bow", 4, 3, 3, 500, "arrow",
    "composite bow", 6, 6, 6, 650, "arrow",
    "compound bow", 7, 7, 7, 700, "arrow",
    "recurve bow", 8, 8, 8, 1000, "arrow",
});
array_bows=sizeof(bows);
arrows = ({
	"flight arrow", 1, 1, 1, 1, "arrow", // >>---->
	"broadhead arrow", 1, 1, 1, 1, "arrow", // >>----->
	"blunt arrow", 1, 1, 1, 1, "arrow", // >>------()
	"bodkin arrow", 1, 1, 1, 1, "arrow", // >>------~
    "forked arrow", 1, 1, 1, 1, "arrow", // >>-------<
});
*/
}

make_crossbow(string str, int i) {
	int x;
	int q;
	object cbow;
	string *id;
	str = lower_case(str);
	x = member_array(str, crossbows);
	if(x < 0) {
	write("You can't craft that crossbow.\n");
	return 0;
    }
    q = i;
	cbow = clone_object(BOW_FILE);
	cbow->set_short(crossbows[x + BOW_NAME]);
	cbow->set_long(get_desc(crossbows[x + BOW_NAME]));
	cbow->set_weight(crossbows[x + BOW_WEIGHT]);
	cbow->set_base_damage(crossbows[x + BOW_BDAMAGE]);
	cbow->set_base_hit(crossbows[x + BOW_BHIT]);
	cbow->set_size(crossbows[x + BOW_SIZE]);
	cbow->set_shoot_time(crossbows[x + BOW_STIME]);
	cbow->set_reload_time(crossbows[x + BOW_RTIME]);
	cbow->set_quality(i);
	cbow->set_maker(this_player()->query_name());
	cbow->set_missile_type("bolt");
	cbow->set_bow_type("crossbow");
	move_object(cbow, this_player());
	this_player()->fix_weight();
    return cbow;
}

make_random_crossbow() {
	int x;
	int r;
	x = random(array_crossbows / 7)*7;
	r = random(100)+1;
	return make_crossbow(crossbows[x + BOW_NAME], r);
}

make_bolt(string str, int i) {
	int x;
	object bolt;
	string *id;
	str = lower_case(str);
	x = member_array(str, bolts);
	if(x < 0) {
	write("You can't craft that bolt.\n");
	return 0;
    }
	bolt = clone_object(ARROW_FILE);
	bolt->set_short(bolts[x + ARROW_NAME]);
	bolt->set_long(get_desc(bolts[x + ARROW_NAME]));
	bolt->set_weight(bolts[x + ARROW_WEIGHT]);
	bolt->set_damage(bolts[x + ARROW_DAMAGE]);
	bolt->set_quality(i);
	bolt->set_hit_chance(bolts[x + ARROW_HIT]);
	bolt->set_crit_chance(bolts[x + ARROW_CRIT]);
	bolt->set_stun_chance(bolts[x + ARROW_STUN]);
	bolt->set_maker(this_player()->query_name());
	bolt->set_missile_type("bolt");
	move_object(bolt, this_player());
	this_player()->fix_weight();
return bolt;
}
get_desc(string str) {
	switch(str) {
	case "flight bolt": return "These bolt are used when somebody is in rush to somewhere and wants to simply shoot one time.";
	case "broadhead bolt": return "The arrowhead of these bolts is very broad. It is something like a standard bolt, quite easy to shoot with but nothing special.";
	case "bodkin bolt": return "The arrowhead of these bolts is made from small awl usually a needle, which is attached to the top. It will certainly hurt when hitted at unprotected bodypart.";
	case "forked bolt": return "The arrowhead of these bolts looks quite much like a simple fork. It will do quite much damage if the target is unprotected.";
	case "blunt bolt": return "These bolts are not used to hurt the enemy but rather to stun and simple get more advance of battle.";
}
return "NODESC";
}