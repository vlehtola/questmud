#define TP this_player()
#define SPCOST TP->query_sp()/4
#define TIME 60+random(60)

inherit "obj/weapon";
int ok;

init() {
        add_action("drain","banish");
        add_action("drain","teleport");
        add_action("drain","relocate");
        add_action("drain","summon");
        ::init();
}

start() {
        set_class(7);
        set_sub_type("staff");
        set_short("The long staff of teleportation");
        set_long("This staff belonged to Zadax, the traveller between worlds. He used it\n"+
                "to help him in his teleportations between different worlds. It is made\n"+
                "from some kind of black wood, the kind you've never seen in Deleria.\n"+
                "It is very long and slender. It seems to be radiating with power and\n"+
                "the air around it quivers a bit. This must be a truly amazing artifact.\n"+
                "You feel that you can 'banish' players, 'teleport' to the inn, 'relocate'\n"+
                "to players and 'summon' them with this staff.\n");
        ok = 1;
}

drain(str) {
        string verb;        
        if(!(this_object() == TP->query_right_weapon() || this_object() == TP->query_left_weapon())) {
                write("You must wield the Staff to use it's powers.\n");
                return 1;
        }

        if(TP->query_sp() < SPCOST) {
                write("You are too weak to handle the staff.\n");
                return 1;
        }

				if ( !ok ) {
					write("You feel that the Staff needs to recharge it's powers.\n");
					return 1;
				}

        write("You invoke the powers of the staff.\n");
        say(TP->query_name()+" invokes the powers of the staff.\n");

        verb = query_verb();

        TP->reduce_sp(SPCOST);
        ok = 0;
        write("You feel weak!\n");
        call_out("use_ok",TIME);
        call_other(this_object(),verb,str);
        return 1;
}

void use_ok() {
	ok = 1;
	if ( wielded_by ) {
		tell_object( wielded_by, "You feel that the Staff is recharged.\n" );
	}
}

banish(str) {
        if(!str) {
                write("Banish who?");
                return 1;
        }
        call_other("/guilds/spells/essence/_exs_fla_loc","resolve",0,str,TP);
        return 1;
}

teleport() {
        write("You teleport to the inn.\n");
        call_other("/guilds/spells/essence/_exs_zzt_trn","resolve",0,0,TP);
        return 1;
}

relocate(str) {
        if(!str) {
                write("Relocate to who?\n");
                return 1;
        }
        call_other("/guilds/spells/essence/_exs_fla_trn","resolve",0,str,TP);
        return 1;
}

summon(str) {
        if(!str) {
                write("Summon who?\n");
                return 1;
        }
        call_other("/guilds/spells/essence/_exs_brr_trn","wand_summon",0,str,TP);
        return 1;
}

check_weapon_break() { return 1; }
