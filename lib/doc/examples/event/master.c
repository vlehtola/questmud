// A NPC handling the event -- Rag

//Treasures are hidden in the outworld
#define MAP "/room/out/outmap"

//The main file
#define FILE "/wizards/rag/events/thunt/start"

//this_player(), doh
#define TP this_player()

//Points needed to win
#define WIN 5

//Eek, a monster!
inherit "obj/monster";

//Who has joined
mapping joins;

//Who has scores
mapping score;

//Coordinates
int x, y;

//You can 'join' the event and get 'info' from it
init() {
        add_action("join","join");
        add_action("info","info");
        ::init();
}

//Basic boring monster stuff
reset(arg) {
        string chat_str;
        ::reset(arg);
        set_race("gnome");
        set_level(90);
        set_name("hoxbah");
        set_alias("gnome");
        set_gender(1);
        set_short("Hoxbah the gnome is here running the treasure hunt");
        set_long("Hoxbah is a very happy-looking gnome. He is wearing a colourful leather jacket\n"+
                "and green trousers. His fingers are covered with precious rings, all full of\n"+
                "glittering jewels. His boots seem to be made of some blue crystal, and like all\n"+
                "gnomish equipment, they look very comfortable. Hoxbah is known for his Legendary\n"+
                "treasure hunt where he or his gnome friends hide something in the wilderness and\n"+
                "then reward the player who finds the most treasures. Obviously, he is very rich\n"+
                "because the reward for winning is very notable. Hoxbah is waving a sign that says\n"+
                "'info' and 'join'\n");

        set_mage(1);
        set_al(0);
        set_log();
        set_aggressive(0);
        set_al_aggr(400);
        
        if (!chat_str) {
                chat_str = allocate(3);
                chat_str[0] = "Hoxbah says: 'Don't be shy!'\n";
                chat_str[1] = "Hoxbah says: 'Join the event here!'\n";
                chat_str[2] = "Hoxbah says: 'You can win money!'\n";
        }
        load_chat(10, chat_str);

//Initialize the event        
        joins = ([ ]);
        score = ([ ]);
        random_xy();
}

//Info!
info() {
        string text;
         text = "The idea of this event is to find treasures hidden in the wilderness.\n";
        text += "You need to 'join' the event to get a map. With the help of the map you\n";
        text += "must then seek the location described in the map. When you think that\n";
        text += "you have reached the location you must 'dig treasure'. The player who\n";
        text += "finds "+WIN+" treasures, wins the event!\n";
        tell_object(TP,text);
        return 1;
}

//Everybody wants to join!
join() {
        if(!joins[TP->query_name()]) {
                say(TP->query_name()+" joins the treasure hunt!\n");
                joins += ([TP->query_name(): (int)1]);
        } else {
                tell_object(TP,"Hoxbah says: 'You have already joined the event!\n'");
        }
	if(!present("map",TP)) {
        	move_object(clone_object("/wizards/rag/event/map"),TP);
        	write("Hoxbah gives you an old map.\n");
	}
        return 1;
}

//The scores for the player 'str'
scores(str) {
        string name, tell;
        string *list;
        int i, siz;
        if(!str) { return; }
        name = str;
        list = m_indices(score);
        siz = sizeof(list);
        
        if(!siz) {
                tell = "Hoxbah tells you 'No scores yet!'\n";
        } else {
                tell = "Hoxbah tells you 'Here are the scores'\n";
                tell += "/--------------|---\\\n";
        
                for(i = 0;i<siz;i++) {
                        tell += sprintf("| %12-s | %i |\n",list[i], score[list[i]]);
                }
                tell += "\\--------------|---/\n";
                tell += "You need "+WIN+" points to win.\n";
        }
        tell_object(find_player(lower_case(name)),tell);
        return 1;
}

//Yeah, someone found the treasure, but did he/she win?
add_score(object ob) {
        object pl, money;
        int prize;
        string name;
        if(!ob) {return;}
        pl = ob;
        name = pl->query_name();
        score[name]++;
        if(score[name] == WIN) {
                prize = (random(20)+21)*25;
                money = clone_object("/obj/new_money");
                money->set_type(4);
                money->set_value(prize);
                move_object(money,pl);
                tell_object(pl,"You win the treasure hunt!\n");
                tell_object(pl,"You receive "+prize+" silver coins!\n");
                pl->set_quest("Win the treasure hunt");
                log_file("thunt", ctime(time())+" "+pl->query_name()+" won "+prize+" silver\n");
                shout("Hoxbah shouts: "+name+" has won the treasure hunt!\n");
                shout("Hoxbah shouts: Wasn't that fun?! See you next time!\n");
                joins = ([ ]);
                score = ([ ]);
                FILE->end_event();
                return 1;
        } else {
                tell_object(pl,"Hoxbah tells you 'Good job!'\n");
                tell_object(pl,"Hoxbah tells you 'A new treasure has been hidden, check your map!\n");
                shout("Hoxbah shouts: "+name+" found the treasure!\n");
                shout("Hoxbah shouts: A new treasure has been hidden, check your maps!\n");
                random_xy();
                return 1;
        }
        return 0;
}

/* Random coordinates for the treasure.
   I should probably check the actual size of
   the map but who cares. Checks if the location
   is ok, that there is more than one map type on
   the map and that it isn't a special place	*/
random_xy() {
 	string mchar1, mchar2;
	x = random(200);
        y = random(200);
	mchar1 = MAP->get_map_char(x,y);
	mchar2 = MAP->get_map_char(x+4,y);
        if(MAP->check_no_walk(mchar1))
        {
                random_xy();
                return 0;
        }
	if(mchar1 == "?" || mchar1 == "#")
	{
		random_xy();
		return 0;
	}
        if(mchar1 == mchar2)
        {
                random_xy();
                return 0;
        }
        return 1;
}

//The map uses these
get_x() { return x; }
get_y() { return y; }
