inherit "obj/monster";

int kailotus;

reset(arg) {
  ::reset(arg);
  if(arg) return;

kailotus = 0;
call_out("kailota",60);
    set_name("Emma the lottery hostess");
    set_alias("emma");
    set_short("Emma the lottery hostess");
    set_long("Tulee joskus.\n");
    set_level(100);
    
    load_chat(2, ({"Emma says 'You should buy some tickets, easy way to get money'\n",
                   "Emma twiddles her thumbs.\n",
                   }));
    
        
    set_al(0);
      
}

void kailota() {
	
int i;
string *str;


switch(kailotus) {
	case 0:
		tell_room(environment(this_object()),this_object()->query_name()+" shouts: Come to Duranghom Lottery-Office located in Casino to buy few tickets. Its easy way to fortune!\n");
		
		break;
	case 1: 
		str = environment(this_object())->get_lottery_winners();
		
		if(sizeof(str) == 0)break;
		for(i=0;i<sizeof(str);i++) {
			if(find_player(lower_case(str[i]))) {
				if(interactive(find_player(lower_case(str[i])))) {
					tell_object(find_player(lower_case(str[i])),"Emma the lottery hostess tells you 'You should come to lotteryoffice to collect your winnings.'\n");
				}
			}
		}
	case 2:
		tell_room(environment(this_object()),this_object()->query_name()+" shouts: Remember to collect your lottery-winnings at the lottery-office!\n");
		break;

	}

kailotus ++;

if(kailotus > 2)kailotus=0;

call_out("kailota",3600); // once in hour.
}

		
		
		