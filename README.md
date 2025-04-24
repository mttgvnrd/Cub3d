# 🎮 cub3D - My First RayCaster with miniLibX  

**42 Firenze Project | Computer Graphics**  
*Implementazione di un motore 3D in stile Wolfenstein 3D utilizzando il ray-casting.*  

---

## 📜 Cosa Richiede il Progetto (Mandatory Part)  

### 🎯 Obiettivi Principali  
- Creare una rappresentazione 3D **first-person** di un labirinto  
- Utilizzare il principio del **ray-casting** con **miniLibX**  
- Parsing di file `.cub` contenenti:  
  - Texture per pareti (NO/SO/EA/WE)  
  - Colori per pavimento e soffitto (F/C)  
  - Mappa con caratteri `0` (spazio), `1` (muro), `N/S/E/W` (posizione iniziale)  

### ⚙️ Funzionalità Richieste  
- **Movimento**:  
  - WASD per spostamento  
  - Frecce per rotazione  
  - ESC per uscire  
- **Rendering**:  
  - Texture diverse per ogni direzione delle pareti  
  - Gestione fluida della finestra (minimizzare, ridimensionamento)  
- **Error Handling**:  
  - Mappa non chiusa → errore  
  - File `.cub` malformato → errore con messaggio esplicito  

## 🎥 Demo
![Demo Video](./clip/example_clip.gif)

## 🛠️ Installazione & Utilizzo  
```bash
git clone https://github.com/mttgvnrd/Cub3d.git
cd cub3D
make  # Compila il progetto

# Esegui con una mappa di esempio
./cub3D maps/map.cub
