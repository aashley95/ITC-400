
  
# this path will only work for Mac/Linux
hosts_path = "/etc/hosts"
# localhost's IP 
redirect = "127.0.0.1"
  
# websites That you want to block
# need to read adblock file to complete this list 
website_list = ["www.facebook.com","facebook.com", 
      "dub119.mail.live.com","www.dub119.mail.live.com", 
      "www.gmail.com","gmail.com"] 
  
while True: 
  
        with open(hosts_path, 'r+') as file: 
            content = file.read() 
            for website in website_list: 
                #if the page we want to block is already in our host file, we do nothing
                if website in content: 
                    pass
                else: 
                    # mapping hostnames to your localhost IP address 
                    file.write(redirect + " " + website + "\n") 