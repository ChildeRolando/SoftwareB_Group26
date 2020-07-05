def regular(domain_file = 'raw_domain.txt', 
            url_file = 'host2ip.txt',
            ip_address = '10.248.98.2'):
  with open(domain_file, 'r') as f:
    txt = f.readlines()
    for i, domain in enumerate(txt):
      txt[i] =  '/^([a-zA-Z\d-_\*@]+\.)+'+\
                domain.strip() +\
                '\.com$/ '+\
                ip_address +\
                '\n'
    with open(url_file, 'w+') as w:
      w.writelines(txt)

if __name__ == "__main__":
    regular()