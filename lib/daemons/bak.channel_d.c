/* It is 3:20 am, Channel daemon is hopefully ready */
/* Channel Daemon by Cendor */
// Altered for 'lite' on 12 November '02 by Nalle
// Added saving messages over boots (in SAVEFILE). -- Nalle 10.10.2003

#include <ansi.h>

#define LEADER_D "/daemons/leader_d"
#define CHANBAN_D "/daemons/chanban_d"
#define COLOURS "/cmds/std/_lite"

#define SAVEFILE "/data/channeldata"

// Added by Nalle on 23Jul02 due to newbie unrest
#define LEVELLIMIT 5

mapping channels;
static string global_channel;

 /* d on log chan // Celtron */
 print_log(string str) 
 {
   if(!this_player() || !this_player()->query_name()) return 0;
   if(str == 0 || str == "") return 0;
   if(sscanf(str, "%s\n", str) == 1) { }
   this_object()->send_to_channel("log", "*"+str+"*");
 }

 reset(arg) 
 {

   if(arg) return;

   if(!mappingp(channels))
    channels=([ "inform": 5; "ChannelD"; "Gameplay info";           ({ }),
                "newbie": 0; "ChannelD"; "Newbies here";            ({ }),
                "chat":   0; "ChannelD"; "Chat here!";              ({ }),
                "sales":  0; "ChannelD"; "Sell&buy channel";        ({ }),
                "mud":    0; "ChannelD"; "English please!";         ({ }),
                "ghost":  0; "ChannelD"; "Voices from heaven";      ({ }),
                "fin":    0; "ChannelD"; "Finnish";                 ({ }),
                "swe":    0; "ChannelD"; "Swedish";                 ({ }),
                "code":   1; "ChannelD"; "Discussion about code";   ({ }),
                "wanted": 0; "ChannelD"; "Ask for stuff you want";  ({ }),
                "alert":  0; "ChannelD"; "Warn others about area spells etc"; ({ }),
		"music":  0; "ChannelD"; "Now playing!";	    ({ }),

                "wiz":    1; "ChannelD"; "Wizard stuff";            ({ }),
                "fiz":    1; "ChannelD"; "Finnish wizards here.";   ({ }),
                "arch":   3; "ChannelD"; "TuneClub MC HC";          ({ }),
                "adm":    4; "ChannelD"; "pervokerho kokoontuu";    ({ }),
                "log":    2; "ChannelD"; "off-game reports";        ({ }),
  ]);

   if(!restore_object(SAVEFILE)) save_object(SAVEFILE);
 }

  static status filter_users(object ob) {
    int lvl;
    if(!environment(ob)) return 0;
    lvl = (int)ob->query_level();
    if((ob->query_invis() && lvl <= this_player()->query_level()) ||
       !ob->query_invis()) {
    return 1;
  }
    return 0;
  }

  add_channel(string arg) {
    string *fog;
    write("This option has been disabled as a useless feature.\n");
    return 1; // disabled due abuse ++Celtron

    if(strlen(arg) >= 10) { write("Too long name.\n");  
       return 1; 
      }
    if(arg=="channels") { write("Illegal name.\n"); return 1; }
    if(this_player()->query_level()<30) { 
     write("You are not experienced enough to create channels.\n");
     return 1;
                                        }
    fog=m_indices(channels);
    if(member_array(arg,fog)==-1) {
      channels+=([arg: 0; this_player()->query_name(); "--"; ({}), ]);
      write("You create channel '"+arg+"'\n");
      this_player()->add_channel(arg);
    }
    else {
      write("But that channel already exists.\n");
    }
    return 1;
  }

  change_topic(chan,topic) {
    string *chans;
    chans=this_player()->query_channel();
    if(strlen(topic) > 40) {
      write("Max. 40 characters allowed.\n");
      return 1;
  }
    if(member_array(chan,chans)==-1) {
      write("You are not on that channel.\n");
      return 1;
  }
    if(!topic) {
      write("Current topic on channel "+chan+" is "+channels[chan,2]+"\n");
      return 1;
  }
    channels[chan,2]=topic;
    this_object()->send_to_channel(chan,"*changes the topic to '"+topic+"'*");
    return 1;
  }

  string kello() {
   string str;
   string tmp1, tmp2, tmp3, tmp4, tmp5;
   if(sscanf(ctime(), "%s %s:%s:%s %s", tmp1, tmp2, tmp3, tmp4, tmp5) == 5)
     tmp2 = extract(tmp2, strlen(tmp2)-2,strlen(tmp2));
   str = tmp2 + ":" + tmp3;
   return str;
  }
/*  following is called by death() //Celtron
send_to_channel("inform", query_real_name()+" dies.", this_object()); */

  send_to_channel(chan,msg, object this_obj) {
    int i;
    object *who;
    object ob;
    string *temp,temp2;
    string *temp_hist;
    string *temp_hist2;
    string color_temp,msg_buffer,temp_buffer;
    if (!this_obj) { this_obj = this_player(); }
    temp = ({ });
    if(interactive(this_obj)) temp = this_obj->query_channel();
    if(member_array(chan,temp) != -1 || channels[chan,0] == 5 ||chan == "log") {
      if(msg) {
        if(msg=="last") {
          write_channel_history(chan);
          return;
        }
       if(this_player() && chan != "inform" && chan != "log") {
         if(CHANBAN_D->query_ban(this_player()->query_real_name(),chan)) {
           write("You are banished from that channel.\n");
           return;
         }
       }
     
     // Added by Nalle on 23Jul02 temporarily due to newbie unrest    
 if(chan!="newbie" && chan!="inform" && chan!="log" && (this_player()->query_level())<LEVELLIMIT) 
              { 
write("Players below level "+LEVELLIMIT+" can only speak on the 'newbie' channel.\n");
      return; }   

       msg_buffer=msg;

       if(this_obj->query_wiz()) {
          temp2="<"+chan+">: ";
        }
        else if(LEADER_D->test_leader(this_obj->query_real_name(),this_obj->query_race()) &&
             this_obj->query_level() > 0 && this_obj->query_race()) {
          temp2="{"+chan+"}: ";
        }
        else {
          temp2="["+chan+"]: ";
        }
        if(chan=="inform") {
          msg=temp2+msg;
        }
        else {
          /* query_real_name -> query_name */
          if(msg[0]==42 && msg[strlen(msg)-1]==42) msg=temp2+capitalize(this_obj->query_name())+" "+msg[1..strlen(msg)-2];
          else msg=capitalize(this_obj->query_name())+" "+temp2+msg;
        }

        temp_hist=channels[chan,3];
        if(sizeof(temp_hist)>20) {
          for(i=sizeof(temp_hist)-21;i<sizeof(temp_hist);i++) {
            if(sizeof(temp_hist2)==0) temp_hist2=({ temp_hist[i] });
            else temp_hist2=temp_hist2+({ temp_hist[i] });
          }
          temp_hist=temp_hist2;
        }
        if(!temp_hist)
          temp_hist = ({ kello() + " " + msg });
        else
          temp_hist=temp_hist+({ kello() + " " + msg });
        channels[chan,3]=temp_hist;

        save_object(SAVEFILE);  // Or save_object is here. - Nalle

        global_channel=chan;
        who=filter_array(users(),"if_on_ch");

        for(i=0;i<sizeof(who);i++) {
          if(who[i]->query_level() > 0 && !who[i]->query_ignore(lower_case(this_obj->query_real_name())) &&
             (chan == "inform" || !who[i]->query_pwd_query())) 
		{
       // Lites -- Nalle
       color_temp=COLOURS->give_color(who[i], chan);
       if(!strlen(color_temp)) color_temp=BOLD;
       temp2=""; msg=msg_buffer;

       if(this_obj->query_wiz()) {
          temp2=color_temp+"<"+chan+">"+OFF+": ";
        }
        else if(LEADER_D->test_leader(this_obj->query_real_name(),this_obj->query_race()) &&
             this_obj->query_level() > 0 && this_obj->query_race()) {
          temp2=color_temp+"{"+chan+"}"+OFF+": ";
        }
        else {
          temp2=color_temp+"["+chan+"]"+OFF+": ";
        }
        if(chan=="inform") {
          msg=temp2+msg;
        }
        else {
          /* query_real_name -> query_name */
          if(msg[0]==42 && msg[strlen(msg)-1]==42) msg=temp2+capitalize(this_obj->query_name())+" "+msg[1..strlen(msg)-2];
          else msg=capitalize(this_obj->query_name())+" "+temp2+msg;
        }
                  tell_object(who[i], msg + "\n");
          	}
        }
      }
    }
    else {
      if(this_player()->query_tester())
        write("Plaa plaa, you are a tester.\n");
    }
  }

  if_on_ch(obj) {
    string *temppi;
    temppi=obj->query_channel();
    if(!temppi) return;
    if(member_array(global_channel,temppi)!=-1) return obj;
  }

  int channel_exists(string arg) {
    string *sumu;
    sumu=m_indices(channels);
    if(member_array(arg,sumu)==-1) return 0;
    else return 1;
  }

  int valid_join(string arg) {
    int ehto;
    ehto=channels[arg,0];
    if(ehto==0 || ehto==5) return 1;
    if(ehto==1 && this_player()->query_wiz() >= 1) return 1;
    if(ehto==2 && this_player()->query_wiz() >= 2) return 1;
    if(ehto==3 && this_player()->query_wiz() >= 3) return 1;
    if(ehto==4 && this_player()->query_wiz() >= 4) return 1;
    return 0;
  }

  int write_channel_who(string arg) {
    string *temp,naame,str;
    object *who;
    int i,x;
    temp=m_indices(channels);
    if(member_array(arg,temp)==-1) return 0;
    if(!valid_join(arg)) {
        write("You don't have access to that channel.\n");
        return 0;
      }
    str=(".[NAME: "+capitalize(arg)+"]==============================.");
    write(extract(str,0,25));
    write(extract("=[CREATOR: "+channels[arg,1]+"]=======",0,19));
    write("=\n");
    global_channel=arg;
    who=filter_array(users(),"filter_users", this_object());
    who=filter_array(who,"if_on_ch");
    who=filter_array(who,"is_visible");
    if(sizeof(who)==0) write("| None.                |\n");
    else {
      for(i=0;i<sizeof(who);i++) {
        x++;
        naame=sprintf("%-20s",who[i]->query_name());
        write("| "+naame+" ");
        if(i%2) {
          write("|\n");
          x=0;
        }
      }
    }
    for(i=x;i>0;i--) {
      write("|                      |\n");
    }
    write("`============================================='\n");
    return 1;
  }
  channel_list() {
    string *temp,str;
    string *temp2;
    int i;
    write("Currently existing channels :\n");
    write("==[NAME]=========[TOPIC]====================\n");
    temp=m_indices(channels);
    for(i=0;i<sizeof(temp);i++) {
      if(valid_join(temp[i])) {
      str=sprintf("%-10s",temp[i])+"|";
      temp2=this_player()->query_channel();
      if(member_array(temp[i],temp2)==-1) str=str+"[OFF]";
      else str=str+"[ON] ";
      str=str+"| "+channels[temp[i],2];
      write(str+"\n");
      }
    }
    return 1;
  }

  write_channel_history(chan) {
    string *history;
    int i;
    history=channels[chan,3];
    write("Last messages on channel "+chan+":\n");
    for(i=0;i<sizeof(history);i++) {
      write(history[i]+"\n");
    }
    return 1;
  }


is_visible(object o)
{
 return !o->query_invisible();
}
