🧭 1. Core Networking Diagnostics (must-know)

These are the “bread and butter” commands every strong engineer should know — especially for debugging connectivity issues, DNS, routing, etc.

| Command                   | Purpose                                          | Typical Use                                                   |
| ------------------------- | ------------------------------------------------ | ------------------------------------------------------------- |
| `ping`                    | Checks reachability and round-trip time          | `ping google.com` → verifies network connectivity             |
| `traceroute` / `tracert`  | Shows network path/hops between hosts            | `traceroute oauth-api.integrationcerner.com`                  |
| `nslookup` / `dig`        | DNS resolution details                           | `nslookup domain.com` / `dig +trace domain.com`               |
| `curl` / `wget`           | Test HTTP(S) requests, headers, and connectivity | `curl -v https://api.example.com/health`                      |
| `telnet` / `nc` (netcat)  | Test TCP connectivity to a port                  | `nc -vz host 443` (very useful for debugging SSL/port issues) |
| `ip addr` / `ifconfig`    | View network interfaces and IPs                  | `ip addr show`                                                |
| `ip route` / `route`      | Show or modify routing table                     | `ip route show`                                               |
| `netstat` / `ss`          | View open ports and network connections          | `ss -tulnp` or `netstat -tulpn`                               |
| `arp`                     | View ARP table (IP ↔ MAC mapping)                | `arp -a`                                                      |
| `hostname`, `hostname -I` | Get system hostname and local IPs                | Useful for quick self-check                                   |

⚙️ 2. Advanced Debugging / Performance Tools

| Command    | Purpose                                        | Example                                      |
| ---------- | ---------------------------------------------- | -------------------------------------------- |
| `lsof -i`  | Lists open network sockets by processes        | `lsof -i :8080` → who’s using port 8080      |
| `tcpdump`  | Capture network packets for analysis           | `tcpdump -i eth0 port 443`                   |
| `nmap`     | Scan open ports / services                     | `nmap -sS 10.32.127.151`                     |
| `ethtool`  | NIC-level details (speed, duplex, link)        | `ethtool eth0`                               |
| `ip neigh` | Show neighbor (ARP) cache                      | Debug local layer 2 connectivity             |
| `ss -s`    | Summarize socket usage (TCP states, counts)    | Helps debug socket leaks                     |
| `mtr`      | Combines `ping` + `traceroute` with live stats | `mtr google.com` for continuous latency view |

🌐 3. HTTP / API Layer Debugging

| Command                                     | Purpose                               | Example                                           |
| ------------------------------------------- | ------------------------------------- | ------------------------------------------------- |
| `curl -v`                                   | Verbose output of request + response  | Debug TLS handshake, redirects                    |
| `curl -I`                                   | Fetch only headers                    | `curl -I https://api.example.com`                 |
| `curl --resolve`                            | Override DNS to test with specific IP | `curl --resolve api.example.com:443:99.83.195.72` |
| `openssl s_client`                          | Test SSL handshake manually           | `openssl s_client -connect api.example.com:443`   |
| `dig +short txt _acme-challenge.domain.com` | Check DNS TXT for certificates        | Debug Let’s Encrypt or Okta configs               |

🧰 4. System & Socket-Level Tools

| Command                      | Purpose                                         |
| ---------------------------- | ----------------------------------------------- |
| `iptables` / `nftables`      | Firewall rules (list, add, delete)              |
| `firewall-cmd` (RHEL/CentOS) | Manage firewall zones                           |
| `ip link` / `ip netns`       | Manage interfaces and namespaces                |
| `ss -tnlp`                   | List listening TCP ports with owning processes  |
| `netcat -l`                  | Simple test server for sockets                  |
| `ip maddr show`              | View multicast addresses (for advanced systems) |

☁️ 5. Cloud / Infra Context (for modern SDEs)

| Area           | Tool / Command                                        | Why it matters                           |
| -------------- | ----------------------------------------------------- | ---------------------------------------- |
| AWS VPC        | `aws ec2 describe-network-interfaces`                 | Understand ENIs, subnets, routing        |
| OCI            | `oci network vcn list`, `oci network route-table get` | Debug VCNs and subnets                   |
| Kubernetes     | `kubectl get svc,pods -o wide`                        | Understand Pod IPs and ClusterIP routing |
| Docker         | `docker network ls`, `docker inspect <container>`     | See how containers are networked         |
| Load Balancers | `curl -I --resolve`                                   | Check traffic routing through ALB/NLB    |

📡 6. DNS and Name Resolution Deep Dive

```dig +trace example.com     # Full resolution chain
dig @8.8.8.8 example.com   # Use specific resolver
host example.com           # Simple lookup
getent hosts example.com   # Check system resolver chain
cat /etc/resolv.conf       # See which DNS your system uses
