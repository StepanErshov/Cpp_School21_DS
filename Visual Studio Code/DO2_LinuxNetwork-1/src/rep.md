# Отчёт по проекту


## Part 1. Инструмент **ipcalc**

**== Задание ==**

#### 1.1. Сети и маски
##### Определи и запиши в отчёт:
##### 1) Адрес сети *192.167.38.54/13*

![ipcalc](/src/D02_photo/ipcalc192.png)

##### 2) Перевод маски *255.255.255.0* в префиксную и двоичную запись, */15* в обычную и двоичную, *11111111.11111111.11111111.11110000* в обычную и префиксную

![ipcalc1](/src/D02_photo/ipcalc255.png)

![ipcalc2](/src/D02_photo/ipcalc15.png)

![ipcalc3](/src/D02_photo/ipcalc1111.png)

##### 3) Минимальный и максимальный хост в сети *12.167.38.4* при масках: */8*, *11111111.11111111.00000000.00000000*, *255.255.254.0* и */4*

![ipcalc4](/src/D02_photo/ipcalc12167384.png)

![ipcalc5](/src/D02_photo/ipcalc121673841111.png)

![ipcalc6](/src/D02_photo/ipcalc12167384255254.png)

#### 1.2. localhost
##### Определи и запиши в отчёт, можно ли обратиться к приложению, работающему на localhost, со следующими IP: *194.34.23.100*, *127.0.0.2*, *127.1.0.1*, *128.0.0.1*

- В контексте компьютерных сетей, термин "localhost" обозначает стандартное доменное имя, предназначенное для обращения к самому себе, то есть к компьютеру, с которого осуществляется запрос. Это имя ассоциируется с диапазоном частных IP-адресов от 127.0.0.1 до 127.255.255.254, которые используются исключительно для внутренних целей и не маршрутизируются в глобальную сеть. Эти адреса назначаются специальному сетевому интерфейсу, известному как "loopback", который позволяет программам на одном и том же компьютере общаться друг с другом через сетевой стек протоколов, минуя реальное сетевое оборудование.

- Проверка 194.34.23.100 P.s. не подходит

![ipcalc7](/src/D02_photo/1.2.1.png)

- Проверка 127.0.0.2 P.s. подходит

![ipcalc8](/src/D02_photo/1.2.2.png)

- Проверка 128.0.0.1 P.s. не подходит

![ipcalc9](/src/D02_photo/1.2.3.png)

- Проверка 127.1.0.1 P.s. подходит

![ipcalc10](/src/D02_photo/1.2.4.png)

#### 1.3. Диапазоны и сегменты сетей
##### Определи и запиши в отчёт:
##### 1) Какие из перечисленных IP можно использовать в качестве публичного, а какие только в качестве частных: *10.0.0.45*, *134.43.0.2*, *192.168.4.2*, *172.20.250.4*, *172.0.2.1*, *192.172.0.1*, *172.68.0.2*, *172.16.255.255*, *10.10.10.10*, *192.169.168.1*

- К частным относятся: 10.0.0.45, 192.168.4.2, 172.20.250.4, 172.16.255.255, 10.10.10.10:

![ipcalc11](/src/D02_photo/1.3.1.png)

![ipcalc12](/src/D02_photo/1.3.2.png)

- К публичным: 134.43.0.2, 172.0.2.1, 192.172.0.1, 172.68.0.2, 192.169.168.1

![ipcalc13](/src/D02_photo/1.3.3.png)

![ipcalc14](/src/D02_photo/1.3.4.png)



##### 2) Какие из перечисленных IP-адресов шлюза возможны у сети *10.10.0.0/18*: *10.0.0.1*, *10.10.0.2*, *10.10.10.10*, *10.10.100.1*, *10.10.1.255*

- Проверим HostMin и HostMax:
    - 10.10.0.2
    - 10.10.10.10
    - 10.10.1.255

![ipcalc15](/src/D02_photo/1.3.5.png)


## Part 2. Статическая маршрутизация между двумя машинами

##### Поднимем две виртуальные машины (далее -- ws1 и ws2).

![ws1-2](/src/D02_photo/2.0.png)

##### С помощью команды `ip a` посмотри существующие сетевые интерфейсы.

![ipa](/src/D02_photo/2.1.png)

##### Опишим сетевой интерфейс, соответствующий внутренней сети, на обеих машинах и зададим следующие адреса и маски: ws1 — *192.168.100.10*, маска */16*, ws2 — *172.24.116.8*, маска */12*.

![2.2](/src/D02_photo/2.2.png)

![2.3](/src/D02_photo/2.3.png)

##### Выполним команду `netplan apply` для перезапуска сервиса сети.

#### 2.1. Добавление статического маршрута вручную
##### Добавим статический маршрут от одной машины до другой и обратно при помощи команды вида `ip r add`.

![2.4](/src/D02_photo/2.4.png)

![2.5](/src/D02_photo/2.5.png)

##### Сразу пропингуем соединение между машинами.


#### 2.2. Добавление статического маршрута с сохранением
##### Перезапустим машины.
##### Добавлю статический маршрут от одной машины до другой с помощью файла */etc/netplan/00-installer-config.yaml*.

![2.6](/src/D02_photo/2.6.png)

![2.7](/src/D02_photo/2.7.png)

##### Пропингуем соединение между машинами.

![2.8](/src/D02_photo/2.8.png)

![2.9](/src/D02_photo/2.9.png)

## Part 3. Утилита **iperf3**

#### 3.1. Скорость соединения
##### Переведи и запиши в отчёт: 8 Mbps в MB/s, 100 MB/s в Kbps, 1 Gbps в Mbps.

- 8 Mbps = 1 MB/s
- 100 MB/s = 819200 Kbps
- 1 Gbps = 1024 Mbps

#### 3.2. Утилита **iperf3**
##### Измерю скорость соединения между ws1 и ws2.

![3.1](/src/D02_photo/3.1.png)

## Part 4. Сетевой экран

#### 4.1. Утилита **iptables**
##### Создай файл */etc/firewall.sh*, имитирующий файрвол, на ws1 и ws2:

```shell
#!/bin/sh

# Удаление всех правил в таблице «filter» (по умолчанию).
iptables -F
iptables -X
```

##### 1) На ws1 применим стратегию, когда в начале пишется запрещающее правило, а в конце пишется разрешающее правило (это касается пунктов 4 и 5).
##### 2) На ws2 применим стратегию, когда в начале пишется разрешающее правило, а в конце пишется запрещающее правило (это касается пунктов 4 и 5).
##### 3) Откроем на машинах доступ для порта 22 (ssh) и порта 80 (http).
##### 4) Запретим *echo reply* (машина не должна «пинговаться», т. е. должна быть блокировка на OUTPUT).
##### 5) Разрешим *echo reply* (машина должна «пинговаться»).
- В отчёт помести скрины с содержанием файла */etc/firewall* для каждой машины.
##### Запустим файлы на обеих машинах командами `chmod +x /etc/firewall.sh` и `/etc/firewall.sh`.

![4.1](/src/D02_photo/4.1ws1.png)

![4.11](/src/D02_photo/4.1ws1sb.png)

![4.111](/src/D02_photo/4.1ws2.png)

![4.1111](/src/D02_photo/4.1ws2sb.png)

- Разница заключается в том, что в первом файле первым подходящим правилом для пакета является запрет, а во втором - разрешение. Применяется только первое подходящее правило, остальные игнорируются.

#### 4.2. Утилита **nmap**
##### Командой **ping** найду машину, которая не «пингуется», после чего утилитой **nmap** покажи, что хост машины запущен.

![4.2](/src/D02_photo/2.8.png)

![4.3](/src/D02_photo/2.9.png)

- nmap 

![4.4](/src/D02_photo/nmap.png)

## Part 5. Статическая маршрутизация сети

Сеть: \
![part5_network](/misc/images/part5_network.png)

##### Поднимим пять виртуальных машин (3 рабочие станции (ws11, ws21, ws22) и 2 роутера (r1, r2)).

![virt](/src/D02_photo/virt.png)

#### 5.1. Настройка адресов машин
##### Настроим конфигурации машин в *etc/netplan/00-installer-config.yaml* согласно сети на рисунке.

##### Как это выглядит по порядку: ws11, ws21, ws22, r1, r2

![conf1](/src/D02_photo/ws11config.png)

![conf2](/src/D02_photo/ws21config.png)

![conf3](/src/D02_photo/ws22config.png)

![conf4](/src/D02_photo/r1config.png)

![conf5](/src/D02_photo/r2config.png)

* Так же для всех машин, чтобы конфигурации вступили в силу, нужно ввести программы `sudo netplan apply`*

##### Перезапустим сервис сети. Если ошибок нет, командой `ip -4 a` проверим, что адрес машины задан верно. Также пропингуем ws22 с ws21. Аналогично пропингуем r1 с ws11.

- Пропингую все машины командой `ip -4 a`

![ip4.1](/src/D02_photo/ipws11.png)

![ip4.2](/src/D02_photo/ipws21.png)

![ip4.3](/src/D02_photo/ipws22.png)

![ip4.4](/src/D02_photo/ipr1.png)

![ip4.5](/src/D02_photo/ipr2.png)

- Проверю пинги ws22 с ws21 и r1 с ws11 

![ws22ws21](/src/D02_photo/pingws22.png)

![r1ws11](/src/D02_photo/pingr1.png)

#### 5.2. Включение переадресации IP-адресов
##### Для включения переадресации IP выполним команду на роутерах:
`sysctl -w net.ipv4.ip_forward=1`

*При таком подходе переадресация не будет работать после перезагрузки системы.*

![ipv4r1](/src/D02_photo/r1ipv4.png)

![ipv4r2](/src/D02_photo/r2ipv4.png)

##### Откроем файл */etc/sysctl.conf* и добавим в него следующую строку:
`net.ipv4.ip_forward = 1`
*При использовании этого подхода, IP-переадресация включена на постоянной основе.*

- r2

![forwardr1](/src/D02_photo/r1forward.png)

- r1

![forwardr2](/src/D02_photo/r2forward.png)

#### 5.3. Установка маршрута по умолчанию
Пример вывода команды `ip r` после добавления шлюза:
```
default via 10.10.0.1 dev eth0
10.10.0.0/18 dev eth0 proto kernel scope link src 10.10.0.2
```
##### Настроим маршрут по умолчанию (шлюз) для рабочих станций. Для этого добавим `default` перед IP-роутера в файле конфигураций.

- ws11

![configr1](/src/D02_photo/ws11config2.png)

- ws21

![configr2](/src/D02_photo/ws21config2.png)

- ws22

![configr3](/src/D02_photo/ws22config2.png)

##### Вызовим `ip r` и покажем, что добавился маршрут в таблицу маршрутизации.

![ipr1](/src/D02_photo/ws11ipr.png)

![ipr2](/src/D02_photo/ws21ipr.png)

![ipr3](/src/D02_photo/ws22ipr.png)

##### Пропингую с ws11 роутер r2 и покажи на r2, что пинг доходит. Для этого используй команду:
`tcpdump -tn -i eth0`

![pingws11](/src/D02_photo/ws11ping.png)

![tcpdumpr2](/src/D02_photo/r2tcpdump.png)

#### 5.4. Добавление статических маршрутов
##### Добавим в роутеры r1 и r2 статические маршруты в файле конфигураций. Пример для r1 маршрута в сетку 10.20.0.0/26:
```shell
# Добавь в конец описания сетевого интерфейса eth1:
- to: 10.20.0.0
  via: 10.100.0.12
```

![r1config](/src/D02_photo/r1config2.png)

![r2config](/src/D02_photo/r2config2.png)

##### Вызовем `ip r` и покажим таблицы с маршрутами на обоих роутерах. Пример таблицы на r1:
```
10.100.0.0/16 dev eth1 proto kernel scope link src 10.100.0.11
10.20.0.0/26 via 10.100.0.12 dev eth1
10.10.0.0/18 dev eth0 proto kernel scope link src 10.10.0.1
```
![r1ipr](/src/D02_photo/r1ipr.png)

![r2ipr](/src/D02_photo/r2ipr.png)

##### Запустим команды на ws11:
`ip r list 10.10.0.0/[маска сети]` и `ip r list 0.0.0.0/0`

![ws11ipr](/src/D02_photo/ws11ipr2.png)

- Маршруты, которые более точно соответствуют целевому IP-адресу, имеют более высокий приоритет. Если есть маршрут для конкретной подсети, он будте иметь более высокий приоритет, чем маршрут по умолчанию

#### 5.5. Построение списка маршрутизаторов
Пример вывода утилиты **traceroute** после добавления шлюза:
```
1 10.10.0.1 0 ms 1 ms 0 ms
2 10.100.0.12 1 ms 0 ms 1 ms
3 10.20.0.10 12 ms 1 ms 3 ms
```
##### Запустим на r1 команду дампа:
`tcpdump -tnv -i eth0`
##### При помощи утилиты **traceroute** построй список маршрутизаторов на пути от ws11 до ws21.

![traceroute](/src/D02_photo/ws11traceroute.png)

![tcpdumprrr](/src/D02_photo/r1tcpdump.png)

- Принцип работы утилиты traceroute заключается в определении маршрута следования пакетов данных от источника к целевому узлу через сеть. Для этого traceroute использует механизм увеличения значения поля TTL ("Time To Live") в IP-пакетах. TTL определяет максимальное количество переходов через маршрутизаторы, которое пакет может совершить, прежде чем будет уничтожен.

 - В начале traceroute отправляет пакеты к целевому узлу с TTL, установленным в 1. Это означает, что пакет должен быть уничтожен первым же маршрутизатором на пути, который также отправляет обратно ICMP-сообщение об ошибке, указывающее на истечение времени жизни пакета. Traceroute записывает адрес этого маршрутизатора и время, затраченное на получение ответа.

 - Затем traceroute повторяет процесс, увеличивая значение TTL на 1, что позволяет пакету пройти через один дополнительный маршрутизатор, прежде чем он будет уничтожен следующим маршрутизатором в цепочке. Этот процесс продолжается, пока пакеты не достигнут целевого узла или не будет достигнуто максимальное значение TTL, указывающее на невозможность достижения цели.

 - Таким образом, traceroute последовательно определяет и записывает адреса всех промежуточных маршрутизаторов на пути к целевому узлу, а также время задержки сигнала от источника до каждого из этих маршрутизаторов и обратно. Это позволяет пользователю видеть путь, которым следуют данные через сеть, и выявлять возможные узкие места или проблемы с маршрутизацией.

#### 5.6. Использование протокола **ICMP** при маршрутизации
##### Запустим на r1 перехват сетевого трафика, проходящего через eth0 с помощью команды:
`tcpdump -n -i eth0 icmp`
##### Пропингуем с ws11 несуществующий IP (например, *10.30.0.111*) с помощью команды:
`ping -c 1 10.30.0.111`

![tcpdump -n -i eth0 icmp](/src/D02_photo/r1icmp.png)

![ping -c 1 10.30.0.111](/src/D02_photo/ws11ping4.png)

## Part 6. Динамическая настройка IP с помощью **DHCP**

`-` Следующим нашим шагом будет более подробное знакомство со службой **DHCP**, которую ты уже знаешь.

**== Задание ==**

*В данном задании используются виртуальные машины из Части 5.*

##### Для r2 настроим в файле */etc/dhcp/dhcpd.conf* конфигурацию службы **DHCP**:
##### 1) Укажим адрес маршрутизатора по умолчанию, DNS-сервер и адрес внутренней сети. Пример файла для r2:
```shell
subnet 10.100.0.0 netmask 255.255.0.0 {}

subnet 10.20.0.0 netmask 255.255.255.192
{
    range 10.20.0.2 10.20.0.50;
    option routers 10.20.0.1;
    option domain-name-servers 10.20.0.1;
}
```
- r2

![6.1](/src/D02_photo/6.1.png)

##### 2) В файле *resolv.conf* пропишим `nameserver 8.8.8.8`.

![6.2.0](/src/D02_photo/6.2.0.png)

##### Перезагрузим службу **DHCP** командой `systemctl restart isc-dhcp-server`(Сделал это выше). Машину ws21 перезагрузи при помощи `reboot` и через `ip a` покажи, что она получила адрес. Также пропингуй ws22 с ws21.

![6.2](/src/D02_photo/6.2.png)

- Пинг ws22 с ws21

![6.3](/src/D02_photo/6.3.png)

##### Укажим MAC-адрес у ws11, для этого в *etc/netplan/00-installer-config.yaml* надо добавить строки: `macaddress: 10:10:10:10:10:BA`, `dhcp4: true`.

![6.4](/src/D02_photo/6.4.png)

##### Для r1 настроим аналогично r2, но сделаем выдачу адресов с жесткой привязкой к MAC-адресу (ws11). Проведём аналогичные тесты.

![6.5](/src/D02_photo/6.5.png)

- Редактируем `/etc/resolv.conf` и перезагружаем DHCP

![6.6](/src/D02_photo/6.6.png)

- Перезагружаем ws11 через sudo reboot и вызываю ip a (ip получен)

![6.7](/src/D02_photo/6.7.png)

- Пингуем ws22 c ws11 

![6.8](/src/D02_photo/6.8.png)

##### Запросим с ws21 обновление IP-адреса.

![6.9](/src/D02_photo/6.9.png)

- Запросим у ws21 обновление IP через sudo dhclient -v
    - v - будет выведена дополнительная информация.

![6.10](/src/D02_photo/6.10.png)

- Проверка IP

![6.11](/src/D02_photo/6.11.png)

- В рамках конфигурации DHCP протокола в шестой части были задействованы следующие параметры:
    - `option routers ip-address [, ip-address...]`: Этот параметр указывает адреса маршрутизаторов (шлюзов) для клиентской сети. Адреса маршрутизаторов должны быть перечислены в порядке убывания предпочтительности. Это означает, что первый в списке маршрутизатор будет использоваться как основной шлюз для выхода в другие сети или интернет.

    - `option domain-name-servers ip-address [ip-address...]`: Этот параметр предоставляет клиентам DHCP список адресов DNS-серверов, которые будут использоваться для разрешения доменных имен. Адреса DNS-серверов также должны быть перечислены в порядке убывания предпочтительности, начиная с наиболее предпочтительного сервера. Это обеспечивает клиентам возможность быстро и эффективно получать информацию о доменных именах, необходимую для доступа к различным ресурсам в интернете.

## Part 7. **NAT**


*В данном задании используются виртуальные машины из Части 5.*
##### В файле */etc/apache2/ports.conf* на ws22 и r1 изменим строку `Listen 80` на `Listen 0.0.0.0:80`, то есть сделаем сервер Apache2 общедоступным.

![7.1](/src/D02_photo/7.1.png)

![7.2](/src/D02_photo/7.2.png)

##### Запустим веб-сервер Apache командой `service apache2 start` на ws22 и r1.

![7.3](/src/D02_photo/7.3.png)

![7.4](/src/D02_photo/7.4.png)

##### Добавим в фаервол, созданный по аналогии с фаерволом из Части 4, на r2 следующие правила:
##### 1) Удаление правил в таблице filter — `iptables -F`;
##### 2) Удаление правил в таблице «NAT» — `iptables -F -t nat`;
##### 3) Отбрасывать все маршрутизируемые пакеты — `iptables --policy FORWARD DROP`.

![7.5](/src/D02_photo/7.5.png)

##### Запустим файл также, как в Части 4.

![7.7](/src/D02_photo/7.7.png)

##### Проверим соединение между ws22 и r1 командой `ping`.
*При запуске файла с этими правилами, ws22 не должна «пинговаться» с r1.*

![7.8](/src/D02_photo/7.8.png)

##### Добавим в файл ещё одно правило:
##### 4) Разрешить маршрутизацию всех пакетов протокола **ICMP**.

![7.9.1](/src/D02_photo/7.9.1.png)

##### Запусти файл также, как в Части 4.

![7.10-7](/src/D02_photo/7.7.png)


##### Проверим соединение между ws22 и r1 командой `ping`.
*При запуске файла с этими правилами, ws22 должна «пинговаться» с r1.*

![7.11](/src/D02_photo/7.11.png)

##### Добавим в файл ещё два правила:
##### 5) Включим **SNAT**, а именно маскирование всех локальных IPиз локальной сети, находящейся за r2 (по обозначениям из Части 5 — сеть 10.20.0.0).
*Совет: стоит подумать о маршрутизации внутренних пакетов, а также внешних пакетов с установленным соединением.*
##### 6) Включим **DNAT** на 8080 порт машины r2 и добавить к веб-серверу Apache, запущенному на ws22, доступ извне сети.
*Совет: стоит учесть, что при попытке подключения возникнет новое tcp-соединение, предназначенное ws22 и 80 порту.*

![7.9-12](/src/D02_photo/7.9.png)

##### Запустим файл также, как в Части 4.
*Перед тестированием рекомендуется отключить сетевой интерфейс **NAT** (его наличие можно проверить командой `ip a`) в VirtualBox, если он включен.*

![7.10-7-13](/src/D02_photo/7.7.png)

##### Проверим соединение по TCP для **SNAT**: для этого с ws22 подключиться к серверу Apache на r1 командой:
`telnet [адрес] [порт]`

![7.10-14](/src/D02_photo/7.10.png)

![7.11-15](/src/D02_photo/7.11.png)

![7.12-16](/src/D02_photo/7.12.png)

##### Проверим соединение по TCP для **DNAT**: для этого с r1 подключиться к серверу Apache на ws22 командой `telnet` (обращаться по адресу r2 и порту 8080).

![7.13-17](/src/D02_photo/7.13.png)

![7.14-18](/src/D02_photo/7.14.png)

![7.15-19](/src/D02_photo/7.15.png)

## Part 8. Дополнительно. Знакомство с **SSH Tunnels**

*В данном задании используются виртуальные машины из Части 5.*

##### Запусти на r2 фаервол с правилами из Части 7.

![8.1](/src/D02_photo/8.1.png)

##### Запустим веб-сервер **Apache** на ws22 только на localhost (то есть в файле */etc/apache2/ports.conf* измени строку `Listen 80` на `Listen localhost:80`).

![8.2](/src/D02_photo/8.2.png)

![8.3](/src/D02_photo/8.3.png)

##### Воспользуемся *Local TCP forwarding* с ws21 до ws22, чтобы получить доступ к веб-серверу на ws22 с ws21.

![8.4](/src/D02_photo/8.4.png)

![8.5](/src/D02_photo/8.5.png)

##### Воспользуйемся *Remote TCP forwarding* c ws11 до ws22, чтобы получить доступ к веб-серверу на ws22 с ws11.

![8.6](/src/D02_photo/8.6.png)

![8.7](/src/D02_photo/8.7.png)

##### Для проверки, сработало ли подключение в обоих предыдущих пунктах, перейдём во второй терминал (например, клавишами Alt + F2) и выполним команду:
`telnet 127.0.0.1 [локальный порт]`\

![8.8](/src/D02_photo/8.8.png)