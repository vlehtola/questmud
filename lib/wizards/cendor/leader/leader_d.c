/* Race leadership system by Cendor */



#define SAVE_FILE "entia"

#define CHANNEL_D "/obj/channel_d"



mapping leaders;

int total_exp;
string name;
int level;

string race_name;



void reset() {

    leaders = ([ ]);

    if(file_size(SAVE_FILE + ".o") > 0) {

    restore_object(SAVE_FILE); 

    }

}



mapping query_leader() { return leaders[this_player()->query_race(),0]; }

mapping query_leaderi(string racee) { return leaders[racee,0]; }





int new_leader() {

  object ob;

  string str;



if(this_player()->query_wiz()) {

  write("Wizards can't lead races.\n");

  return 1;

}

    str = to_string(query_leaderi(this_player()->query_race()));

    str = lower_case(str);

    ob = find_player(str);

    if(ob) ob->save_me(1);

    if(!restore_object("/players/"+str)) {

    total_exp = 0;

    name = 0;

    level = 0;

}

    str = lower_case(str);

     

if(this_player() -> query_level() < level) {

    write("You are not enough powerful to get the leadership.\n");

    return 1;

}

else if(this_player() -> query_level() == level) {

  if(this_player() -> query_total_exp() < total_exp) {

    write("You are not enough powerful to get the leadership.\n");

    return 1;

 }

}

    if(this_object()->query_leader() == this_player()->query_real_name()) { 

    write("You already lead the " + capitalize(this_player()->query_race()) + " race.\n");

    return 1;  }

    leaders -= ([ this_player()->query_race() ]);

    leaders += (([ this_player()->query_race():this_player()->query_real_name() ]));

    save_object(SAVE_FILE);

    write("You are now the leader of " + this_player()->query_race() + " race.\n");

    CHANNEL_D->send_to_channel("inform", capitalize(this_player()->query_real_name()) + " is now the new leader of " + capitalize(this_player()->query_race()) + " race.");

    return 1;

}



int remove_leader(string pam) {

  if(!pam) return 0;

  pam = lower_case(pam);

  leaders -= ([ pam ]);

  return 1;

}



int test_leader(string name, string race) {

    if(!name) return -1;

    if(!race) return -1;

    name = lower_case(name);

    race = lower_case(race);

    if(name == this_object()->query_leaderi(race)) {

    return 1;

    } else {

    return 0;

    }

}





