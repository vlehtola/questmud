string channels_last;
string channels;
object listeners;

reset(arg) {
  int i;
  if(arg) { return; }
  listeners = allocate(30);
  channels = allocate(30);
  channels_last = allocate(30);
  while(i<sizeof(channels_last)) {
    channels_last[i] = allocate(25);
    listeners[i] = allocate(100);
    i += 1;
  }
  channels[0] = "inform";
  channels[1] = "mud";
  channels[2] = "fin";
  channels[3] = "wiz";
  channels[4] = "sales";
}
chan_names(str) {
  int i;
  while(i<sizeof(channels) && channels[i]) {
    if(channels[i]==str) {
	return 1;
    }
    i += 1;
  }
}

join_chans(name) {
  channels_join(name,"fin",1);
  channels_join(name,"mud",1);
  channels_join(name,"inform",1);
  channels_join(name,"sales",1);
  if(name->query_wiz()) {
    channels_join(name,"wiz",1);
  }
}

channels_what(name,string str) {
  log_file("Chan_log",ctime(time())+" "+name->query_name()+": "+str+"\n");
  if(!str) {
    write("See 'help channels'.\n");
    return 1;
  }
  if(sscanf(str,"send %s", str) == 1) {
    if(sscanf(str, "inform %s", str) == 1) {
	if(str=="last") { display_last(0); }
	return;
    }
    if(!str||str == ""|| str==0) { return; }
    channels_say(name,str);
    return 1;
  }
  if(sscanf(str,"join %s", str) == 1) {
    channels_join(name,str);
    return 1;
  }
  if(sscanf(str,"leave %s", str) == 1) {
    channels_leave(name,str);
    return 1;
  }
  if(sscanf(str,"create %s", str) == 1) {
    channels_create(name,str);
    return 1;
  }
  if(sscanf(str,"who %s", str) == 1) {
    channels_who(name,str);
    return 1;
  }
  write("See 'help channels'.\n");
  return 1;
}

display_last(num) {
  int i;
  object lista;
  lista = channels_last[num];
  i=sizeof(lista)-1;
  while(i>=0) {
    if(lista[i]) { write(lista[i]); }
    i -= 1;
  }
}

private_check(chan,name) {
  if(chan=="wiz" && !name->query_wiz()) return 1;
}

channels_say(name,str) {
  int i,ii;
  string msg, channel, c_str,emote;
  object lista;
  log_file("Chan_log",ctime(time())+" "+name->query_name()+": "+str+" (say)\n");
  if(!str || sscanf(str,"%s %s", channel, msg) != 2 || msg == 0 || msg == "0") {
    write("Usage: channels send <channel> <msg>\n");
    return 1;
  }
  if (private_check(channel,name)) return;
  while(i<sizeof(channels) && channels[i]) {
    if(channels[i] == channel) {
	if(!msg) { return; }
	if(msg=="last") {
	  display_last(i);
	  return 1;
	}
	if(sscanf(msg,"*%s*",emote) == 1) { msg = emote; }
	if(name->query_wiz()) {
	  c_str = "<"+channel+">";
	} else {
	  c_str = "["+channel+"]";
	}
	lista = listeners[i];
	ii =0;
	while(ii<sizeof(lista) && lista[ii]) {
	  if(emote) {
	    lista[ii]->lited(c_str);
            tell_object(lista[ii],": "+ name->query_name());
            tell_object(lista[ii], " "+emote+"\n");
	  } else {
	    tell_object(lista[ii], name->query_name());
	    lista[ii]->lited(" "+c_str);
            tell_object(lista[ii], ": "+msg+"\n");
	  }
	  ii += 1;
	}
        if(emote) {
	  add_last(i,c_str+": "+name->query_name()+" "+emote+"\n");
	} else {
  	  add_last(i,name->query_name()+" "+c_str+": "+msg+"\n");
 	}
	i=sizeof(channels);
    }
    i += 1;
  }
}

add_last(num,str) {
  int i;
  string lista;
  lista = channels_last[num];
  i = sizeof(lista)-1;
  while(i>0) {
    lista[i] = lista[i-1];
    i -= 1;
  }
  lista[0] = extract(ctime(time()), 11, 15)+" "+str;
}

channels_leave(name,str) {
  int i,ii;
  object lista;
  while(i<sizeof(channels) && channels[i]) {
    if(channels[i] == str) {
	lista = listeners[i];
	while(ii<sizeof(lista) && lista[ii]) {
	  if(name == lista[ii]) {
	    lista[ii] = 0;
	    listeners[i] = lista[ii];
	    write("You leave channel "+str+".\n");
	    return 1;
	  }
	  ii += 1;
        }
    }
    i += 1;
  }
  return 1;
}

channels_join(name,str,arg) {
  int i,ii;
  object lista;
  if(str=="wiz" && !name->query_wiz()) { return; }
  while(i<sizeof(channels) && channels[i]) {
    if(channels[i] == str) {
	lista = listeners[i];
    }
    i += 1;
  }
  while(ii<sizeof(lista) && lista[ii]) {
    if(lista[ii] == name) {
	write("You already listen "+str+" channel.\n");
	return 1;
    }
    ii += 1;
  }
  if(ii>=sizeof(lista)) {
    if(!arg) { write("Channel "+str+" is unjoinable.\n"); }
    return 1;
  }
  lista[ii] = name;
  listeners[i] = lista[ii];
  if(!arg) { write("You join the "+str+" channel.\n"); }
  return 1;
}

channels_create(name,str) {
  write("Option disabled.\n");
  return 1;
}

channels_who(name,str) {
  int i,ii;
  object lista;
  write("Channel "+str+" listeners:\n");
  while(i<sizeof(channels) && channels[i]) {
    if(channels[i] == str) {
	lista = listeners[i];
	while(ii<sizeof(lista) && lista[ii]) {
	  if(ii == (ii/2)*2) {
	    if(strlen(lista[ii]->query_name()) < 9) {
  	      write(lista[ii]->query_name() +"\t\t");
	    } else {
	      write(lista[ii]->query_name()+"\t");
	    }
	  } else {
	    write(lista[ii]->query_name()+"\n");
	  }
	  ii += 1;
	}
	write("\n");
    }
    i+=1;
  }
  return 1;
}
