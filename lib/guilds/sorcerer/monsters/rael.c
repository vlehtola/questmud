#define GUILDRANK_D "/daemons/guildrank_d"
inherit "obj/monster";

reset(arg) {
object amuletti;

  string str;
  ::reset(arg);
  if(arg) return;
  set_level(90);
        set_max_hp(query_max_hp()*3);
        set_str(query_str()*2);
        set_dex(query_dex()*2);
        set_con(query_con()*2);
  set_name("rael");
  set_alias("archsorcerer");
  set_short("The archsorcerer of the planets, Rael Idium");
  set_long("A tall man with long white hair and a white cloak is walking\n"+
           "walking around the room. Man is wearing a shining amulet which\n"+
           "is the symbol of archsorcerers. Rael is teacher of all sorcerers.\n"+
           "If you need your sorcerer staff this is the man who can help you. You might want to ask about it from him.\n");
  set_al_aggr(300);
        set_skill("two weapons combat", 100);
set_skill("attack", 100);
set_mage();
  str = allocate(4);
  str[0] = "Rael mumbles something.\n";
  str[1] = "Rael says: 'Ah Izyldran my god, bless me with your wisdom.'\n";
  str[2] = "Rael summons a bench and sits on it.\n";
  str[3] = "Rael says: 'If you need your staff I might be able to help you!'\n";
  load_chat(15,str);
  set_gender(1);
  set_log();
        amuletti = clone_object("/guilds/sorcerer/obj/amulet.c");
        move_object(amuletti, this_object());
init_command("wear amulet");
}

ask_question(str) {
        string rank, guild;
        object staffi;
        int score;
        guild = "sorcerer";
        if(str == "staff") {
          if( GUILDRANK_D->is_member_of_guild(this_player(), guild) ) {
                score = GUILDRANK_D->count_rank_score(this_player(), guild, 0, 0);
                GUILDRANK_D->define_max_score(guild);
                rank = GUILDRANK_D->get_rank_status(guild, score);
                if(this_player()->query_tester() || this_player()->query_wiz()) {
                  write("Rank: "+rank+".\n");
                }
                if(rank == "an apprentice scholar of the will") {
                             write("Rael says: 'Ah welcome young master.'\n");
                                staffi = clone_object("/guilds/obj/staff.c");
                } else if(rank == "a scholar of the will") {
                             write("Rael says: 'Study more and one day you will be a archsorcerer just like me!'\n");
                                staffi = clone_object("/guilds/obj/staff.c");
                } else if(rank == "an apprentice sorcerer of the will") {
                             write("Rael says: 'Oh you have just learn the basics!\n");
                                staffi = clone_object("/guilds/obj/staff.c");
                } else if(rank == "a sorcerer of the will") {
                             write("Rael says: 'Ooh good a sorcerer!\n");
                                staffi = clone_object("/guilds/obj/staff.c");
                } else if(rank == "an aura creator of the will") {
                             write("Rael says: 'Not yet a master but an aura creator\n");
                                staffi = clone_object("/guilds/obj/staff.c");
                } else if(rank == "a grand sorcerer of the will") {
                             write("Rael says: 'Grand sorcerer.. you still need some learning.\n");
                                staffi = clone_object("/guilds/obj/staff.c");
                } else if(rank == "an archsorcerer of the will") {
                             write("Rael says: 'An archsorcerer. You have mastered it all but do you have faith?\n");
                                staffi = clone_object("/guilds/obj/staff.c");
                 } else {
                        write("You are not allowed to receive the staff");
                        return 1;
                }
                if(present("sor_staff",this_player())) {
                        write("Rael says: 'You cannot have two staffs!\n");
                        return 1;
                }

                if(staffi) {
                        write("Rael says: 'Well here is your staff. Use it well\n");
                        move_object(staffi,this_player());
                        return 1;
                }
          }
         }
}
