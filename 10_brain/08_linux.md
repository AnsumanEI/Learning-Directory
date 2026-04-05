# 08 — Linux
> Topics: File System · Permissions · Processes · SSH · Cron · Systemctl  
> Environment: Kali Linux on ASUS ROG G15 (F8 at boot)

---

## 🧠 The Big Idea

Linux is the operating system that runs on virtually every server in the world. As a backend engineer, you will live in the terminal. These aren't just commands to memorise — they're the tools you use to operate servers, debug issues, and automate tasks.

**Rule:** Always type commands manually. Never copy-paste. Your fingers need to remember this.

---

## File System Navigation

```bash
pwd                    # print working directory — where am I?
ls                     # list files
ls -la                 # list all files including hidden, with permissions
cd /path/to/dir        # change directory
cd ..                  # go up one level
cd ~                   # go to home directory
mkdir dirname          # make directory
mkdir -p a/b/c         # make nested directories
rm file.txt            # remove file
rm -r dirname          # remove directory recursively
cp file.txt dest/      # copy file
cp -r dir/ dest/       # copy directory
mv file.txt newname    # rename or move
```

---

## Reading Files

```bash
cat file.txt           # print entire file
tail file.txt          # print last 10 lines
tail -f file.txt       # follow file — updates live (great for logs)
tail -n 50 file.txt    # last 50 lines
head file.txt          # first 10 lines
less file.txt          # scroll through file (q to quit)
```

---

## Writing to Files

```bash
echo "hello" > file.txt    # write (overwrites)
echo "hello" >> file.txt   # append (adds to end)
```

---

## Searching

```bash
grep -r "text" .           # search for "text" recursively from current dir
grep -r "text" /path/      # search in specific path
grep -i "text" file.txt    # case-insensitive search
find . -name "*.cpp"       # find all .cpp files from here
find . -name "main.py"     # find specific file
```

⚠️ **Struggle:** `grep "text"` without the dot → doesn't know where to search. Always add `.` for current directory.

---

## Permissions

Every file has 3 permission sets: **owner · group · others**  
Each set has: **read (r=4) · write (w=2) · execute (x=1)**

```bash
ls -la
# -rwxr-xr-- 1 arun arun 1234 Apr 4 server
#  ↑↑↑↑↑↑↑↑↑
#  │││││││││
#  ││└──┘└──┘└── others: r-- = 4
#  │└──┘└─────── group:  r-x = 5
#  └──┘└──────── owner:  rwx = 7
```

```bash
chmod 755 file     # owner=rwx(7), group=r-x(5), others=r-x(5)
chmod 644 file     # owner=rw-(6), group=r--(4), others=r--(4)
chmod +x file      # add execute permission
```

| chmod | Who can do what |
|---|---|
| 755 | Owner: full. Others: read+execute. Common for scripts |
| 644 | Owner: read+write. Others: read only. Common for files |
| 600 | Owner only. Used for SSH private keys |

---

## Processes

```bash
ps aux             # list all running processes
ps aux | grep name # find a specific process
top                # live process monitor (q to quit)
htop               # better live monitor (if installed)
kill <PID>         # send SIGTERM — politely ask process to stop
kill -9 <PID>      # send SIGKILL — force kill immediately
```

**PID** = Process ID. Every running program has one. Find it with `ps aux`.

```bash
# Example: kill a FastAPI server
ps aux | grep uvicorn
kill 12345          # PID from above
```

---

## Disk & Memory

```bash
df -h              # disk usage of all filesystems (human readable)
du -sh .           # size of current directory
du -sh *           # size of each item in current directory
free -m            # RAM usage in megabytes
```

---

## Networking Tools

```bash
ip a               # show all network interfaces and IPs
curl http://url    # make HTTP GET request
curl -I http://url # fetch headers only
curl -k https://url # ignore SSL certificate errors
sudo tcpdump -i wlan0 port 80 -n   # capture HTTP traffic on wifi
sudo tcpdump -i any port 8000 -n   # capture traffic on any interface
```

---

## SSH — Secure Shell

SSH lets you log into a remote machine securely.

```bash
# Generate key pair
ssh-keygen -t rsa
# Creates:
# ~/.ssh/id_rsa      ← private key (NEVER share this)
# ~/.ssh/id_rsa.pub  ← public key (safe to share)

# Connect to remote machine
ssh user@ip_address

# Connect with specific key
ssh -i key.pem user@ip_address

# Connect to localhost (test SSH locally)
ssh localhost

# Exit SSH session
exit
```

### Key files
```
~/.ssh/id_rsa        ← your private key
~/.ssh/id_rsa.pub    ← your public key
~/.ssh/known_hosts   ← fingerprints of servers you've connected to
~/.ssh/authorized_keys ← (on server) public keys allowed to connect
```

### How SSH auth works
```
1. You connect → server sends its fingerprint
2. Your client checks known_hosts — seen before?
3. Server checks authorized_keys — is your public key there?
4. If yes → you're in, no password needed
```

---

## Systemctl — Managing Services

```bash
sudo systemctl status ssh      # is SSH running?
sudo systemctl start ssh       # start it
sudo systemctl stop ssh        # stop it
sudo systemctl restart ssh     # stop + start
sudo systemctl enable ssh      # start automatically on boot
sudo systemctl disable ssh     # don't start on boot
```

**Service** = a background program managed by the OS. SSH, nginx, postgres — all services.

---

## Cron — Scheduled Tasks

Cron runs commands on a schedule automatically.

```bash
crontab -e    # edit your cron jobs (opens in nano/vim)
crontab -l    # list current cron jobs
```

### Cron syntax

```
*  *  *  *  *  command
│  │  │  │  └── day of week (0=Sunday, 1=Monday ... 6=Saturday)
│  │  │  └───── month (1-12)
│  │  └──────── day of month (1-31)
│  └─────────── hour (0-23)
└────────────── minute (0-59)
```

### Examples

```
* * * * *          every minute
*/5 * * * *        every 5 minutes
0 0 * * *          midnight every day
0 9 * * 1          Monday at 9am
0 9 * * 1-5        weekdays at 9am
30 18 * * *        6:30pm every day
```

⚠️ **Struggle:** `* 12 * * *` does NOT mean midnight. It means "every minute of the 12th hour" = every minute between 12:00 and 12:59. Midnight = `0 0 * * *`.

### Test a cron job

```bash
# Write timestamps to a file every minute
* * * * * echo "$(date)" >> /tmp/crontest.txt

# Watch the file update
tail -f /tmp/crontest.txt
```

---

## 🔁 Quick Revision Cheatsheet

### 5 commands to type cold before every Linux session

```bash
grep -r "text" .
ps aux | grep uvicorn
chmod 755 server.cpp
systemctl status ssh
crontab -l
```

### The commands that matter most right now

```bash
# Navigation
ls -la / cd / mkdir / rm -r / cp -r / mv

# Files
cat / tail -f / grep -r "text" . / find . -name "*.cpp"

# Permissions
chmod 755 / chmod 644

# Processes
ps aux / kill <PID> / kill -9 <PID>

# Disk/RAM
df -h / free -m

# SSH
ssh user@ip / ssh-keygen -t rsa / ssh localhost

# Services
sudo systemctl status/start/stop/restart ssh

# Cron
crontab -e / crontab -l

# Network
ip a / curl http://url / sudo tcpdump -i any port 8000 -n
```