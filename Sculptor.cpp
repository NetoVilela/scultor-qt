#include <iostream>
#include <cstdlib>
#include <fstream>

#include "Sculptor.h"

Sculptor::Sculptor(int _nx, int _ny, int _nz){
  r = g = b = a = 1; // Default colors configuration
  nx = _nx;
  ny = _ny;
  nz = _nz;

  v = new Voxel **[ny];
  for (int i = 0; i < ny; i++) {
    v[i] = new Voxel *[nx];
    for (int j = 0; j < nx; j++){
     v[i][j] = new Voxel [nz];
    }
  }
}

void Sculptor::clearAll(){
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++){
      for (int k = 0; k < nz; k++){
        cutVoxel(i, j, k);
      }
    }
  }
}

Sculptor::~Sculptor(){
  for (int i = 0; i < nx; i++){
    for (int j = 0; j < ny; j++){
      delete[] v[i][j];
    }
    delete[] v[i];
  }
  delete[] v;
}

void Sculptor::setColor(float r_, float g_, float b_, float alpha_){
  r = r_;
  g = g_;
  b = b_;
  a = alpha_;
}

void Sculptor::putVoxel(int x, int y, int z){
  if(!((x >= 0 && x <= nx) && (y >= 0 && y <= ny) && (z >= 0 && z <= nz))){ return; }

  Voxel *current_voxel = &v[x][y][z];
  if(r >= 0.0 && r <= 1.0) current_voxel -> r = r;
  if(g >= 0.0 && g <= 1.0) current_voxel -> g = g;
  if(b >= 0.0 && b <= 1.0) current_voxel -> b = b;
  if(a >= 0.0 && a <= 1.0) current_voxel -> a = a;
  current_voxel -> isOn = true;
}

void Sculptor::cutVoxel(int x, int y, int z){
  if(!((x >= 0 && x <= nx) && (y >= 0 && y <= ny) && (z >= 0 && z <= nz))){ return; }
  v[x][y][z].isOn = false;
}

void Sculptor::writeOFF(std::string filename){
  Voxel *current_voxel;
  std::ofstream output_file;
  output_file.open(filename);
  if(!output_file.is_open()){
    std::cout << "[Error] There was an error reading/writing the file ("<< filename << ")."<< std::endl;
    exit(1);
  }

  int counter = 0;
  for(int i = 0; i < nx; i++){
    for(int j = 0; j < ny; j++){
      for(int k = 0; k < nz; k++){
        current_voxel = &v[i][j][k];
        if(current_voxel -> isOn) counter++;
      }
    }
  }

  int number_of_vertices = 8*counter;
  int number_of_edges = 6*counter;

  output_file << "OFF" << std::endl;
  output_file << number_of_vertices << " "
       << number_of_edges << " "
       << 0 << " " << std::endl;

  for(int i = 0; i < nz; i++){
    for(int j = 0; j < ny; j++){
      for(int k = 0; k < nx; k++){
        current_voxel = &v[i][j][k];
        if(current_voxel -> isOn){
          output_file << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl
             << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl
             << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl
             << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl
             << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl
             << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl
             << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl
             << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
        }
      }
    }
  }

  int current_face = 0;
  for(int i=0; i<nx; i++){
    for(int j=0; j<ny; j++){
      for(int k=0; k<nz; k++){
        current_voxel = &v[i][j][k];
        if(current_voxel -> isOn){
          output_file << 4 << " " << 0 + current_face << " " << 3 + current_face << " " << 2 + current_face << " " << 1 + current_face << " "
               << current_voxel -> r << " " << current_voxel -> g << " " << current_voxel -> b << " " << current_voxel -> a/1.0 << std::endl
               << 4 << " " << 4 + current_face << " " << 5 + current_face << " " << 6 + current_face << " " << 7 + current_face<< " "
               << current_voxel -> r << " " << current_voxel -> g << " " << current_voxel -> b << " " << current_voxel -> a/1.0 << std::endl
               << 4 << " " << 0 + current_face << " " << 1 + current_face << " " << 5 + current_face << " " << 4 + current_face << " "
               << current_voxel -> r << " " << current_voxel -> g << " " << current_voxel -> b << " " << current_voxel -> a/1.0 << std::endl
               << 4 << " " << 0 + current_face << " " << 4 + current_face << " " << 7 + current_face << " " << 3 + current_face << " "
               << current_voxel -> r << " " << current_voxel -> g << " " << current_voxel -> b << " " << current_voxel -> a/1.0 << std::endl
               << 4 << " " << 3 + current_face << " " << 7 + current_face << " " << 6 + current_face << " " << 2 + current_face << " "
               << current_voxel -> r << " " << current_voxel -> g << " " << current_voxel -> b << " " << current_voxel -> a/1.0 << std::endl
               << 4 << " " << 1 + current_face << " " << 2 + current_face << " " << 6 + current_face << " " << 5 + current_face<< " "
               << current_voxel -> r << " " << current_voxel -> g << " " << current_voxel -> b << " " << current_voxel -> a/1.0 << std::endl;
          current_face += 8;
        }
      }
    }
  }

  output_file.close();
}

std::vector<std::vector<Voxel>> Sculptor::readMx(int dimension, int plan){
    std::vector<std::vector<Voxel>> planVoxels;
    std::vector<Voxel> lineVoxels;

    switch(plan) {
      case XY:
        lineVoxels.resize(ny);
        for(int i = 0; i<nx; i++){
            for(int j = 0; j<ny; j++){
                Voxel *voxel = &v[i][j][dimension];
                lineVoxels[j].isOn = voxel -> isOn;
                lineVoxels[j].r = (int)(voxel -> r * 255.0);
                lineVoxels[j].g = (int)(voxel -> g * 255.0);
                lineVoxels[j].b = (int)(voxel -> b * 255.0);
                lineVoxels[j].a = (int)(voxel -> a * 255.0);
            }
            planVoxels.push_back(lineVoxels);
        }
        break;
      case YZ:
        lineVoxels.resize(nz);
        for(int i = 0; i<ny; i++){
            for(int j = 0; j<nz; j++){
                Voxel *voxel = &v[dimension][i][j];
                lineVoxels[j].isOn = voxel -> isOn;
                lineVoxels[j].r = (int)(voxel -> r * 255.0);
                lineVoxels[j].g = (int)(voxel -> g * 255.0);
                lineVoxels[j].b = (int)(voxel -> b * 255.0);
                lineVoxels[j].a = (int)(voxel -> a * 255.0);
            }
            planVoxels.push_back(lineVoxels);
        }
        break;
      case ZX:
        lineVoxels.resize(nx);
        for(int i = 0; i<nz; i++){
            for(int j = 0; j<nx; j++){
                Voxel *voxel = &v[j][dimension][i];
                lineVoxels[j].isOn = voxel -> isOn;
                lineVoxels[j].r = (int)(voxel -> r * 255.0);
                lineVoxels[j].g = (int)(voxel -> g * 255.0);
                lineVoxels[j].b = (int)(voxel -> b * 255.0);
                lineVoxels[j].a = (int)(voxel -> a * 255.0);
            }
            planVoxels.push_back(lineVoxels);
        }
      break;
    }
    lineVoxels.clear();
    return planVoxels;
}
