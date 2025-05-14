# D-marrage-avec-ROS2-Humble-Installation-configuration-et-compilation-sur-Raspberry-Pi-4

# Mon Workspace ROS 2 - Humble

Ce dépôt contient le workspace ROS 2 utilisé pour mes projets avec `colcon`.

## Structure
- `src/`: Contient les packages ROS 2 développés
- `build/`, `install/`, `log/`: Générés automatiquement par `colcon build`

## Utilisation
```bash
source /opt/ros/humble/setup.bash
colcon build --symlink-install
source install/setup.bash
