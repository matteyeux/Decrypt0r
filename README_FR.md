#Decrypt0r

Télécharger ici https://github.com/matteyeux/Decrypt0r/releases/download/Decrypt0r/Decrypt0r.zip


Extrat0r est un outil simple qui permet de decrypter les rootfs et le kernelcache des firmwares IPSW d'iOS.
Vous pouvez executer le programme en double cliquant sur l'executable ou directement via une invite de commande.

### Decryptage de rootfs

Pour décrypter les rootfs il suffit de télécharger le fichier IPSW à la racine du dossier.
Il faut bien sur avoir la clé des rootfs pour le firmware disponible sur 
https://www.theiphonewiki.com/wiki/Firmware_Keys

Vous entrez le nom du fichier IPSW (ex : iPhone5,4_8.4.1_12H321_Restore.ipsw).
Le programme vous demande ensuite d'entrer la clé des rootfs que vous avez au préalable obtenue.

Le programme va ensuite decompresser le firmware dans le dossier IPSW.
Ensuite vous devrez indiquer le fichier de type dmg contenant les rootfs (ex : 058-24465-023.dmg).
Dans le dossier IPSW, il y aura 3 fichiers dmg, celui des rootfs est le plus lourd.

Le programme va ensuite travailler tout seul.

Si vous souhaitez modifier les rootfs (ex : supprimer setup.app -ASR n'acceptera pas le firmware sans exploit BootROM) vous pouvez utiliser TransMac.

###Encryptage des rootfs et création d'un Custom Fimware

Vous pouvez maintenant créer votre propre Custom Fimware.
Downgrade toujours impossible sans SHSHs, sur les appareils qui n'ont pas d'exploit BootROM.
Donc cette fonction est inutile ? 
Oui, mais ça peut toujours servir.

###Decryptage des autres composants du firmware

Pour decrypter les autres composants, ils vous faut seulement copier les clés.
Vous devrez entrer le nom du fichier (ex : kernelcache.release.n49, pour le kernelcache).
Vous entrez ensuite la clé pour le kernelcache disponible aussi sur theiphonewiki.com.
Puis vous entrez la clé IV disponible sur le même site.

Le programme va ensuite decrypter automatiquement

Vous pourrez ensuite faire ce que vous voulez avec.

##TODO

- Ajouter une version pour GNU/Linux et OS X
- Rendre Open Source mon code
- Cleaner mon code
- Traduire en anglais
- Rendre le programme plus simple d'utilisation


##Credits

Merci à Jam Elrhk Elro (@Elro74) pour son script Liberati0n et son aide pour le dev.
Developpé par Mathieu Hautebas (@matteyeux)

Pour ce petit outil j'ai utilisé :

- xpwn developpé par Planetbeing https://github.com/planetbeing/xpwn
- dmg.exe (Aucune idée de comment je l'ai eu).
- 7zip.exe (developpé par Igor Pavlov)

Pour plus d'informations contactez-moi sur Twitter : matteyeux.
