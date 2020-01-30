// Lottery-daemon to QuestMUD by Astarel

// defines
#define LOTTO_TICKET_COST 1000 // Cost of one ticket in bronze
#define LOTTO_MAXNUM 15 // the highest lotto_number
#define LOTTO_PRICE 100000 // The "pohjakassa" of lottery
#define LOTTO_HITS_NEEDED 4 // You can change this but if you do, you have to change the share_winnings() also.
#define LOTTO_SAVE "/data/lotto"
#define WEEK_IN_SECONDS 604800 

inherit "room/room";

// global vars.
mapping mapp; // this is the mapping that must be saved everytime. This helds the information of tickets,
mapping lottery_winners;
static mapping winners; // no need for saving this mapping. Only used when the lottery is held.
int potti;
int lottery_time;
static status callout_flag;
string last_lottonumbers;

// protos

status lottery_buy(string str);
status lottery_held();
string *generate_lotto_array();
mapping query_tickets() { return mapp; }
mapping query_lottery_winners() { return lottery_winners; }
mapping query_winners() { return winners; }
void clear_lottery();
status share_winnings(mapping mapp);
status lottery_redeem(string str);
string *get_lottery_winners() {
	
string *str;

	str = m_indices(lottery_winners);
	
return str;

}

string query_last_lottery_numbers() { return last_lottonumbers; }


// code
reset(status arg) {

int temp;
/*
if(!present("Emma the lottery hostess",this_object())) {
	move_object(clone_object("/wizards/astarel/lotto/emma"),this_object());
}
*/

if(!potti)potti = LOTTO_PRICE;

lottery_time = 1013022000;

last_lottonumbers = "0 0 0 0 0 0 0";

mapp = ([ ]);
winners = ([ ]);
lottery_winners = ([ ]);

set_not_out(1);
set_light(3);
set_short("The Lottery-office");
set_long("The nice and warm lottery-office of Duranghom.\n"+
         "There is a small sign in the corner you should read.\n");
add_exit("north", "/world/casino/middleroom");
set_items(({"sign","Maybe you should read this sign?\n"}));

restore_object(LOTTO_SAVE);


if(!callout_flag) {
	
	temp = lottery_time - time();
	if(remove_call_out("lottery_held") == -1)call_out("lottery_held",temp);
	callout_flag = 1;
}

}


init() {
        ::init();
        add_action("lottery_buy","buy");
        //add_action("lottery_held","held");
        add_action("lottery_collect","collect");
        add_action("lottery_help","read");
        add_action("lottery_check","check");
        
        }

status lottery_check(string str) {
int i,a,b,potti1,potti2,itemp;
string *tickets;
string *numbers;
mapping tempmapp;

itemp = potti;


	if(!str) {
		write("Usage: check tickets | pots \n");
		return 1;
	}
	
	if(str == "tickets") {
		if(!mapp[this_player()->query_name()]) {
		write("Before you can check your tickets, you should buy some tickets.\n");
		return 1;
		}
	
		tickets = m_indices(mapp[this_player()->query_name()]);
		a=1;

		tempmapp = mapp[this_player()->query_name()];

		write("You have "+sizeof(tickets)+" ticket(s).\n");

		for(i=0;i<sizeof(tickets);i++) {
	
		write("Ticket "+a+": ");
		numbers = tempmapp[tickets[i]];
		for(b=0;b<sizeof(numbers);b++) {
			write(numbers[b]+", ");
			}
		write("\n");
		a++;
		}
	return 1;
	}	
	if(str == "pots") {
		
		write("The current pots are: \n");
		
		potti1 = potti/2;
		potti -= potti1;

		potti2 = potti/2;
		potti -= potti2;

		potti1 += potti;	
			
		potti = itemp;
	
		write("5 hits: "+potti1+" bronze divined by the amount of winners\n");
		write("4 hits: "+potti2+" bronze divined by the amount of winners\n");
		
	return 1;
}

return 1;
}

status lottery_help(string str) {
string poks;

	if(str == "sign") {
	write("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"+
	      " Cost of one ticket is "+LOTTO_TICKET_COST+" bronze coins.\n"+
	      " You have to choose 5 numbers between 1 and "+LOTTO_MAXNUM+".\n"+
	      " The last lottery numbers were: "+last_lottonumbers+"\n"+
	      " Next lottery will be held: "+ctime(lottery_time)[0..15]+".\n"+
	      " To buy a ticket type: \n"+
	      " buy ticket Num1 Num2 Num3 Num4 Num5.\n"+
	      " OR buy ticket random\n"+
	      " To collect your winnings type:\n"+
	      " collect winnings\n"+
	      " To check your tickets type:\n"+
	      " check tickets\n"+
	      " To check the current pots type: \n"+
	      " check pots\n"+
	      " Direct all whining, ideas and bugreports to Astarel.\n"+
	      "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	}
return 1;
}
		


status lottery_collect(string str) {

if(!str) {
	write("Usage: collect winnings\n");
	return 1;
}
if(str != "winnings") {
	write("Usage: collect winnings\n");
	return 1;
}

if(!lottery_winners[this_player()->query_name()]) {
        write("You dont have any winnings!\n");
        return 1;
        }

write("Congratulations "+this_player()->query_name()+"! You have just won "+lottery_winners[this_player()->query_name()]+" bronze coins!\n");
this_player()->add_money(lottery_winners[this_player()->query_name()]);
lottery_winners = lottery_winners - ([ this_player()->query_name() ]);

save_object(LOTTO_SAVE);

return 1;
}


status lottery_buy(string arg) {

int i1,i2,i3,i4,i5,i;
string *arr;
mapping temp_map;

        if(!arg) {
        write("Syntax: buy ticket Num1 Num2 Num3 Num4 Num5\n");
        return 1;
        }

	if((this_player()->total_money()/100) < LOTTO_TICKET_COST) {
		write("You dont have enough money!");
		return 1;
	}
	
	if(arg == "ticket random") {
		
		arr = generate_lotto_array();
		
		i = random(sizeof(arr));
	        i1 = to_int(arr[i]);
        	arr = arr - ({ arr[i], });

        	i = random(sizeof(arr));
        	i2 = to_int(arr[i]);
        	arr = arr - ({ arr[i], });


        	i = random(sizeof(arr));
        	i3 = to_int(arr[i]);
        	arr = arr - ({ arr[i], });


        	i = random(sizeof(arr));
        	i4 = to_int(arr[i]);
        	arr = arr - ({ arr[i], });


        	i = random(sizeof(arr));
        	i5 = to_int(arr[i]);
        	arr = arr - ({ arr[i], });

		}
		
		
	
        	else if(sscanf(arg,"ticket %d %d %d %d %d",i1,i2,i3,i4,i5) != 5) {
        	write("Syntax: buy ticket Num1 Num2 Num3 Num4 Num5\n");
        	write("    OR: buy ticket random\n");
        	return 1;
        	}

        if(!i1 || !i2 || !i3 || !i4 || !i5) {
        write("Syntax: buy ticket Num1 Num2 Num3 Num4 Num5\n");
        write("    OR: buy ticket random\n");
        return 1;
        }

        if(i1 > LOTTO_MAXNUM || i1 < 1) {
        write("The numbers should be between 1 and "+LOTTO_MAXNUM+"\n");
        return 1;
        }

        if(i2 > LOTTO_MAXNUM || i2 < 1) {
        write("The numbers should be between 1 and "+LOTTO_MAXNUM+"\n");
        return 1;
        }

        if(i3 > LOTTO_MAXNUM || i3 < 1) {
        write("The numbers should be between 1 and "+LOTTO_MAXNUM+"\n");
        return 1;
        }

        if(i4 > LOTTO_MAXNUM || i4 < 1) {
        write("The numbers should be between 1 and "+LOTTO_MAXNUM+"\n");
        return 1;
        }

        if(i5 > LOTTO_MAXNUM || i5 < 1) {
        write("The numbers should be between 1 and "+LOTTO_MAXNUM+"\n");
        return 1;
        }

        if(i1 == i2 || i1 == i3 || i1 == i4 || i1 == i5) {
                write("Choose different numbers!\n");

        return 1;
        }
        if(i2 == i1 || i2 == i3 || i2 == i4 || i2 == i5) {
                write("Choose different numbers!\n");

        return 1;
        }
        if(i3 == i2 || i3 == i1 || i3 == i4 || i3 == i5) {
                write("Choose different numbers!\n");

        return 1;
        }
        if(i4 == i2 || i4 == i3 || i1 == i4 || i4 == i5) {
                   write("Choose different numbers!\n");

        return 1;
        }
        if(i5 == i2 || i5 == i3 || i5 == i4 || i1 == i5) {
                write("Choose different numbers!\n");

        return 1;
        }

	this_player()->reduce_money(LOTTO_TICKET_COST,3);
	potti += LOTTO_TICKET_COST;

        if(mapp[this_player()->query_name()]) {

         temp_map = mapp[this_player()->query_name()];

         mapp[this_player()->query_name()] = temp_map += ([sizeof(m_indices(temp_map)): ({i1,i2,i3,i4,i5,}), ]);

                }

        else mapp += ([this_player()->query_name():([0:({i1,i2,i3,i4,i5,}), ]), ]);

	write("You buy a ticket with numbers: "+i1+" "+i2+" "+i3+" "+i4+" "+i5+"\n");
	
save_object(LOTTO_SAVE);
return 1;
}


string *generate_lotto_array()  {
string *temp;
int i,tempi;

temp = ({ });

for(i=0;i<LOTTO_MAXNUM;i++) {
        tempi = random(LOTTO_MAXNUM)+1;
        if(member_array(tempi,temp) == -1)temp += ({ tempi, });
        else i--;
}
return temp;
}

void clear_lottery() {

mapp = ([ ]);
winners = ([ ]);
//potti = 0;
save_object(LOTTO_SAVE);
}

status lottery_held() {

int b1,b2,b3,b4,b5,i,b,osumia,c;
string *arr;
string *temp_array;
string *ticket_numbers;


mapping temp_map;
mapping temp_mapp;


arr = m_indices(mapp);
        if(sizeof(arr) == 0) {
                //write("No need for helding lottery.\n");
                lottery_time += WEEK_IN_SECONDS;
		potti += LOTTO_PRICE;
                clear_lottery();
                return 1;
                }

arr = generate_lotto_array();
        i = random(sizeof(arr));
        b1 = to_int(arr[i]);
        arr = arr - ({ arr[i], });

        i = random(sizeof(arr));
        b2 = to_int(arr[i]);
        arr = arr - ({ arr[i], });


        i = random(sizeof(arr));
        b3 = to_int(arr[i]);
        arr = arr - ({ arr[i], });


        i = random(sizeof(arr));
        b4 = to_int(arr[i]);
        arr = arr - ({ arr[i], });


        i = random(sizeof(arr));
        b5 = to_int(arr[i]);
        arr = arr - ({ arr[i], });

shout("The lottery has been held!\n");
shout("The lottery-numbers are: "+b1+", "+b2+", "+b3+", "+b4+", "+b5+"\n");
shout("Come and collect your winnigs at Duranghom Lottery-Office as soon as possible!\n");
last_lottonumbers = b1+" "+b2+" "+b3+" "+b4+" "+b5;


arr = m_indices(mapp);

for(i=0;i<sizeof(arr);i++) {

osumia = 0;


temp_array = m_indices(mapp[arr[i]]); // all tickets-array of specific player:
temp_map = mapp[arr[i]]; // ticket-mapping of specific player

for(b=0;b<sizeof(temp_array);b++) {

ticket_numbers = temp_map[temp_array[b]]; //numbers of one ticket

osumia = 0;

for(c=0;c<5;c++) {

if(to_int(ticket_numbers[c]) == b1) {
        osumia += 1;
        }
if(to_int(ticket_numbers[c]) == b2) {
        osumia += 1;
        }
if(to_int(ticket_numbers[c]) == b3) {
        osumia += 1;
        }
if(to_int(ticket_numbers[c]) == b4) {
        osumia += 1;
        }
if(to_int(ticket_numbers[c]) == b5) {
        osumia += 1;
        }

        }
if(osumia >= LOTTO_HITS_NEEDED) {

        if(winners[arr[i]]) {
                temp_mapp = winners[arr[i]];
                winners[arr[i]] = temp_mapp + ([sizeof(m_indices(temp_mapp)):osumia,]);
                }
        else winners += ([arr[i]: ([0:osumia,]), ]);
        }
        }
        }

if(sizeof(m_indices(winners)) >= 1) {
        // Put here a message if you want announce the winners.
        share_winnings(winners);
        return 1;
}

lottery_time += WEEK_IN_SECONDS;
potti += LOTTO_PRICE;

save_object(LOTTO_SAVE);

clear_lottery();
return 1;
}

status share_winnings(mapping mappi) {

string *names1; // 5 oikein voittajat
string *names2; // 4 oikein voittajat

string *arr;
string *temps;
int i,a;

mapping tickets;

int potti1; // 5 oikein potti
int potti2; // 4 oikein potti



names1 = ({ });
names2 = ({ });


potti1 = potti/2;
potti -= potti1;

potti2 = potti/2;
potti -= potti2;

potti1 += potti;

arr = m_indices(mappi);

for(i=0;i<sizeof(mappi);i++) {

tickets = mappi[arr[i]];

temps = m_indices(tickets);

for(a=0;a<sizeof(temps);a++) {


if(to_int(tickets[temps[a]]) == 5) {
        names1 = names1 + ({ arr[i], });
        continue;
        }

if(to_int(tickets[temps[a]]) == 4) {
        names2 = names2 + ({ arr[i], });
        continue;
        }

}

}


if(sizeof(names1) >0)potti1 /= sizeof(names1);
if(sizeof(names2) >0)potti2 /= sizeof(names2);

for(i=0;i<sizeof(names1);i++) {

      if(find_player(lower_case(names1[i]))) {
        if(interactive(find_player(lower_case(names1[i])))) {
        tell_object(find_player(lower_case(names1[i])),"You just won "+potti1+" in lottery! You can get your money from the lottery-office!\n");
        }
}

if(lottery_winners[names1[i]]) {

        lottery_winners[names1[i]] += potti1;

        }
else lottery_winners += ([ names1[i]:potti1, ]);

log_file("lotto","- "+names1[i]+" won "+potti1+" "+ctime(time())+"\n");

}

for(i=0;i<sizeof(names2);i++) {
       
if(find_player(lower_case(names2[i]))) {
        if(interactive(find_player(lower_case(names2[i])))) {
        tell_object(find_player(lower_case(names2[i])),"You just won "+potti2+" in lottery! You can get your money from the lottery-office!\n");
        }
}

if(lottery_winners[names2[i]]) {

        lottery_winners[names2[i]] += potti2;

        }
else lottery_winners += ([ names2[i]:potti2, ]);

log_file("lotto","- "+names2[i]+" won "+potti2+" "+ctime(time())+"\n");
}

lottery_time += WEEK_IN_SECONDS;

potti = LOTTO_PRICE;

save_object(LOTTO_SAVE);

clear_lottery();

return 1;

}