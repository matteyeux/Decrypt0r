#Decrypt0r

Decryp0r est un outil simple qui permet de decrypter les rootfs et le kernelcache des firmwares IPSW d'iOS. <br>
Vous pouvez executer le programme en double cliquant sur l'executable ou directement via une invite de commande. <br>

### Decryptage de rootfs

Pour décrypter les rootfs il suffit de télécharger le fichier IPSW à la racine du dossier. <br>
Il faut bien sur avoir la clé des rootfs pour le firmware disponible sur
https://www.theiphonewiki.com/wiki/Firmware_Keys <br>

Vous entrez le nom du fichier IPSW (ex : iPhone5,4_8.4.1_12H321_Restore.ipsw). <br>
Le programme vous demande ensuite d'entrer la clé des rootfs que vous avez au préalable obtenue. <br>

Le programme va ensuite decompresser le firmware dans le dossier IPSW. <br>
Ensuite vous devrez indiquer le fichier de type dmg contenant les rootfs (ex : 058-24465-023.dmg). <br>
Dans le dossier IPSW, il y aura 3 fichiers dmg, celui des rootfs est le plus lourd. <br>

Le programme va ensuite travailler tout seul. <br>

Si vous souhaitez modifier les rootfs (ex : supprimer setup.app -ASR n'acceptera pas le firmware sans exploit BootROM) vous pouvez utiliser TransMac. <br>

###Encryptage des rootfs et création d'un Custom Fimware

Vous pouvez maintenant créer votre propre Custom Fimware. <br>
Downgrade toujours impossible sans SHSHs, sur les appareils qui n'ont pas d'exploit BootROM. <br>
Donc cette fonction est inutile ?  <br>
Oui, mais ça peut toujours servir. <br>

###Decryptage des autres composants du firmware <br>

Pour decrypter les autres composants, ils vous faut seulement copier les clés. <br>
Vous devrez entrer le nom du fichier (ex : kernelcache.release.n49, pour le kernelcache). <br>
Vous entrez ensuite la clé pour le kernelcache disponible aussi sur theiphonewiki.com. <br>
Puis vous entrez la clé IV disponible sur le même site. <br>

Le programme va ensuite decrypter automatiquement <br>

Vous pourrez ensuite faire ce que vous voulez avec. <br>

## Comment compiler ?

Pour compiler c'est tout simple, vous vous rendez dans le dossier decrypt0r et vous tapez la commande `make` <br>

##Credits

Merci à Jam Elrhk Elro ([@Elro74](https://twitter.com/Elro74)) pour son script Liberati0n et son aide pour le dev.<br>
Developpé par Mathieu Hautebas ([@matteyeux](https://twitter.com/matteyeux)) <br>

Pour ce petit outil j'ai utilisé : <br>

- xpwn et dmg developpés par Planetbeing https://github.com/planetbeing/xpwn <br>
- 7zip.exe (developpé par Igor Pavlov) <br>
- ipsw.me par [Callum Jones](https://twitter.com/icj_)
Pour plus d'informations contactez-moi sur Twitter : [@matteyeux](https://twitter.com/matteyeux). <br>
