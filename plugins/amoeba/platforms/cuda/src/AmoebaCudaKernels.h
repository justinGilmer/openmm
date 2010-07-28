#ifndef AMOEBA_OPENMM_CUDAKERNELS_H_
#define AMOEBA_OPENMM_CUDAKERNELS_H_

/* -------------------------------------------------------------------------- *
 *                              AmoebaOpenMM                                  *
 * -------------------------------------------------------------------------- *
 * This is part of the OpenMM molecular simulation toolkit originating from   *
 * Simbios, the NIH National Center for Physics-Based Simulation of           *
 * Biological Structures at Stanford, funded under the NIH Roadmap for        *
 * Medical Research, grant U54 GM072970. See https://simtk.org.               *
 *                                                                            *
 * Portions copyright (c) 2008 Stanford University and the Authors.           *
 * Authors:                                                                   *
 * Contributors:                                                              *
 *                                                                            *
 * This program is free software: you can redistribute it and/or modify       *
 * it under the terms of the GNU Lesser General Public License as published   *
 * by the Free Software Foundation, either version 3 of the License, or       *
 * (at your option) any later version.                                        *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU Lesser General Public License for more details.                        *
 *                                                                            *
 * You should have received a copy of the GNU Lesser General Public License   *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.      *
 * -------------------------------------------------------------------------- */

#include "amoebaKernels.h"
#include "openmm/System.h"
#include "AmoebaCudaData.h"

namespace OpenMM {

/**
 * This kernel is invoked by AmoebaHarmonicBondForce to calculate the forces acting on the system and the energy of the system.
 */
class CudaCalcAmoebaHarmonicBondForceKernel : public CalcAmoebaHarmonicBondForceKernel {
public:
    CudaCalcAmoebaHarmonicBondForceKernel(std::string name, 
                                          const Platform& platform,
                                          AmoebaCudaData& data,
                                          System& system);
    ~CudaCalcAmoebaHarmonicBondForceKernel();
    /**
     * Initialize the kernel.
     * 
     * @param system     the System this kernel will be applied to
     * @param force      the AmoebaHarmonicBondForce this kernel will be used for
     */
    void initialize(const System& system, const AmoebaHarmonicBondForce& force);
    /**
     * Execute the kernel to calculate the forces.
     * 
     * @param context    the context in which to execute this kernel
     */
    void executeForces(ContextImpl& context);
    /**
     * Execute the kernel to calculate the energy.
     * 
     * @param context    the context in which to execute this kernel
     * @return the potential energy due to the AmoebaHarmonicBondForce
     */
    double executeEnergy(ContextImpl& context);
private:
    int numBonds;
    AmoebaCudaData& data;
    System& system;
};

/**
 * This kernel is invoked by AmoebaHarmonicAngleForce to calculate the forces acting on the system and the energy of the system.
 */
class CudaCalcAmoebaHarmonicAngleForceKernel : public CalcAmoebaHarmonicAngleForceKernel {
public:
    CudaCalcAmoebaHarmonicAngleForceKernel(std::string name, const Platform& platform, AmoebaCudaData& data, System& system);
    ~CudaCalcAmoebaHarmonicAngleForceKernel();
    /**
     * Initialize the kernel.
     * 
     * @param system     the System this kernel will be applied to
     * @param force      the AmoebaHarmonicAngleForce this kernel will be used for
     */
    void initialize(const System& system, const AmoebaHarmonicAngleForce& force);
    /**
     * Execute the kernel to calculate the forces.
     * 
     * @param context    the context in which to execute this kernel
     */
    void executeForces(ContextImpl& context);
    /**
     * Execute the kernel to calculate the energy.
     * 
     * @param context    the context in which to execute this kernel
     * @return the potential energy due to the AmoebaHarmonicAngleForce
     */
    double executeEnergy(ContextImpl& context);
private:
    int numAngles;
    AmoebaCudaData& data;
    System& system;
};

/**
 * This kernel is invoked by AmoebaHarmonicInPlaneAngleForce to calculate the forces acting on the system and the energy of the system.
 */
class CudaCalcAmoebaHarmonicInPlaneAngleForceKernel : public CalcAmoebaHarmonicInPlaneAngleForceKernel {
public:
    CudaCalcAmoebaHarmonicInPlaneAngleForceKernel(std::string name, const Platform& platform, AmoebaCudaData& data, System& system);
    ~CudaCalcAmoebaHarmonicInPlaneAngleForceKernel();
    /**
     * Initialize the kernel.
     * 
     * @param system     the System this kernel will be applied to
     * @param force      the AmoebaHarmonicInPlaneAngleForce this kernel will be used for
     */
    void initialize(const System& system, const AmoebaHarmonicInPlaneAngleForce& force);
    /**
     * Execute the kernel to calculate the forces.
     * 
     * @param context    the context in which to execute this kernel
     */
    void executeForces(ContextImpl& context);
    /**
     * Execute the kernel to calculate the energy.
     * 
     * @param context    the context in which to execute this kernel
     * @return the potential energy due to the AmoebaHarmonicInPlaneAngleForce
     */
    double executeEnergy(ContextImpl& context);
private:
    int numAngles;
    AmoebaCudaData& data;
    System& system;
};

/**
 * This kernel is invoked by AmoebaTorsionForce to calculate the forces acting on the system and the energy of the system.
 */
class CudaCalcAmoebaTorsionForceKernel : public CalcAmoebaTorsionForceKernel {
public:
    CudaCalcAmoebaTorsionForceKernel(std::string name, const Platform& platform, AmoebaCudaData& data, System& system);
    ~CudaCalcAmoebaTorsionForceKernel();
    /**
     * Initialize the kernel.
     * 
     * @param system     the System this kernel will be applied to
     * @param force      the AmoebaTorsionForce this kernel will be used for
     */
    void initialize(const System& system, const AmoebaTorsionForce& force);
    /**
     * Execute the kernel to calculate the forces.
     * 
     * @param context    the context in which to execute this kernel
     */
    void executeForces(ContextImpl& context);
    /**
     * Execute the kernel to calculate the energy.
     * 
     * @param context    the context in which to execute this kernel
     * @return the potential energy due to the AmoebaTorsionForce
     */
    double executeEnergy(ContextImpl& context);
private:
    int numTorsions;
    AmoebaCudaData& data;
    System& system;
};

/**
 * This kernel is invoked by AmoebaPiTorsionForce to calculate the forces acting on the system and the energy of the system.
 */
class CudaCalcAmoebaPiTorsionForceKernel : public CalcAmoebaPiTorsionForceKernel {
public:
    CudaCalcAmoebaPiTorsionForceKernel(std::string name, const Platform& platform, AmoebaCudaData& data, System& system);
    ~CudaCalcAmoebaPiTorsionForceKernel();
    /**
     * Initialize the kernel.
     * 
     * @param system     the System this kernel will be applied to
     * @param force      the AmoebaPiTorsionForce this kernel will be used for
     */
    void initialize(const System& system, const AmoebaPiTorsionForce& force);
    /**
     * Execute the kernel to calculate the forces.
     * 
     * @param context    the context in which to execute this kernel
     */
    void executeForces(ContextImpl& context);
    /**
     * Execute the kernel to calculate the energy.
     * 
     * @param context    the context in which to execute this kernel
     * @return the potential energy due to the AmoebaPiTorsionForce
     */
    double executeEnergy(ContextImpl& context);
private:
    int numPiTorsions;
    AmoebaCudaData& data;
    System& system;
};

/**
 * This kernel is invoked by AmoebaStretchBendForce to calculate the forces acting on the system and the energy of the system.
 */
class CudaCalcAmoebaStretchBendForceKernel : public CalcAmoebaStretchBendForceKernel {
public:
    CudaCalcAmoebaStretchBendForceKernel(std::string name, const Platform& platform, AmoebaCudaData& data, System& system);
    ~CudaCalcAmoebaStretchBendForceKernel();
    /**
     * Initialize the kernel.
     * 
     * @param system     the System this kernel will be applied to
     * @param force      the AmoebaStretchBendForce this kernel will be used for
     */
    void initialize(const System& system, const AmoebaStretchBendForce& force);
    /**
     * Execute the kernel to calculate the forces.
     * 
     * @param context    the context in which to execute this kernel
     */
    void executeForces(ContextImpl& context);
    /**
     * Execute the kernel to calculate the energy.
     * 
     * @param context    the context in which to execute this kernel
     * @return the potential energy due to the AmoebaStretchBendForce
     */
    double executeEnergy(ContextImpl& context);
private:
    int numStretchBends;
    AmoebaCudaData& data;
    System& system;
};

/**
 * This kernel is invoked by AmoebaOutOfPlaneBendForce to calculate the forces acting on the system and the energy of the system.
 */
class CudaCalcAmoebaOutOfPlaneBendForceKernel : public CalcAmoebaOutOfPlaneBendForceKernel {
public:
    CudaCalcAmoebaOutOfPlaneBendForceKernel(std::string name, const Platform& platform, AmoebaCudaData& data, System& system);
    ~CudaCalcAmoebaOutOfPlaneBendForceKernel();
    /**
     * Initialize the kernel.
     * 
     * @param system     the System this kernel will be applied to
     * @param force      the AmoebaOutOfPlaneBendForce this kernel will be used for
     */
    void initialize(const System& system, const AmoebaOutOfPlaneBendForce& force);
    /**
     * Execute the kernel to calculate the forces.
     * 
     * @param context    the context in which to execute this kernel
     */
    void executeForces(ContextImpl& context);
    /**
     * Execute the kernel to calculate the energy.
     * 
     * @param context    the context in which to execute this kernel
     * @return the potential energy due to the AmoebaOutOfPlaneBendForce
     */
    double executeEnergy(ContextImpl& context);
private:
    int numOutOfPlaneBends;
    AmoebaCudaData& data;
    System& system;
};

/**
 * This kernel is invoked by AmoebaTorsionTorsionForce to calculate the forces acting on the system and the energy of the system.
 */
class CudaCalcAmoebaTorsionTorsionForceKernel : public CalcAmoebaTorsionTorsionForceKernel {
public:
    CudaCalcAmoebaTorsionTorsionForceKernel(std::string name, const Platform& platform, AmoebaCudaData& data, System& system);
    ~CudaCalcAmoebaTorsionTorsionForceKernel();
    /**
     * Initialize the kernel.
     * 
     * @param system     the System this kernel will be applied to
     * @param force      the AmoebaTorsionTorsionForce this kernel will be used for
     */
    void initialize(const System& system, const AmoebaTorsionTorsionForce& force);
    /**
     * Execute the kernel to calculate the forces.
     * 
     * @param context    the context in which to execute this kernel
     */
    void executeForces(ContextImpl& context);
    /**
     * Execute the kernel to calculate the energy.
     * 
     * @param context    the context in which to execute this kernel
     * @return the potential energy due to the AmoebaTorsionTorsionForce
     */
    double executeEnergy(ContextImpl& context);
private:
    int numTorsionTorsions;
    int numTorsionTorsionGrids;
    AmoebaCudaData& data;
    System& system;
};

/**
 * This kernel is invoked by AmoebaMultipoleForce to calculate the forces acting on the system and the energy of the system.
 */
class CudaCalcAmoebaMultipoleForceKernel : public CalcAmoebaMultipoleForceKernel {
public:
    CudaCalcAmoebaMultipoleForceKernel(std::string name, const Platform& platform, AmoebaCudaData& data, System& system);
    ~CudaCalcAmoebaMultipoleForceKernel();
    /**
     * Initialize the kernel.
     * 
     * @param system     the System this kernel will be applied to
     * @param force      the AmoebaMultipoleForce this kernel will be used for
     */
    void initialize(const System& system, const AmoebaMultipoleForce& force);
    /**
     * Execute the kernel to calculate the forces.
     * 
     * @param context    the context in which to execute this kernel
     */
    void executeForces(ContextImpl& context);
    /**
     * Execute the kernel to calculate the energy.
     * 
     * @param context    the context in which to execute this kernel
     * @return the potential energy due to the AmoebaMultipoleForce
     */
    double executeEnergy(ContextImpl& context);
private:
    int numMultipoles;
    AmoebaCudaData& data;
    System& system;
};

/**
 * This kernel is invoked by AmoebaMultipoleForce to calculate the forces acting on the system and the energy of the system.
 */
class CudaCalcAmoebaGeneralizedKirkwoodForceKernel : public CalcAmoebaGeneralizedKirkwoodForceKernel {
public:
    CudaCalcAmoebaGeneralizedKirkwoodForceKernel(std::string name, const Platform& platform, AmoebaCudaData& data, System& system);
    ~CudaCalcAmoebaGeneralizedKirkwoodForceKernel();
    /**
     * Initialize the kernel.
     * 
     * @param system     the System this kernel will be applied to
     * @param force      the AmoebaMultipoleForce this kernel will be used for
     */
    void initialize(const System& system, const AmoebaGeneralizedKirkwoodForce& force);
    /**
     * Execute the kernel to calculate the forces.
     * 
     * @param context    the context in which to execute this kernel
     */
    void executeForces(ContextImpl& context);
    /**
     * Execute the kernel to calculate the energy.
     * 
     * @param context    the context in which to execute this kernel
     * @return the potential energy due to the AmoebaMultipoleForce
     */
    double executeEnergy(ContextImpl& context);
private:
    AmoebaCudaData& data;
    System& system;
};

/**
 * This kernel is invoked by AmoebaMultipoleForce to calculate the forces acting on the system and the energy of the system.
 */
class CudaCalcAmoebaSASAForceKernel : public CalcAmoebaSASAForceKernel {
public:
    CudaCalcAmoebaSASAForceKernel(std::string name, const Platform& platform, AmoebaCudaData& data, System& system);
    ~CudaCalcAmoebaSASAForceKernel();
    /**
     * Initialize the kernel.
     * 
     * @param system     the System this kernel will be applied to
     * @param force      the AmoebaMultipoleForce this kernel will be used for
     */
    void initialize(const System& system, const AmoebaSASAForce& force);
    /**
     * Execute the kernel to calculate the forces.
     * 
     * @param context    the context in which to execute this kernel
     */
    void executeForces(ContextImpl& context);
    /**
     * Execute the kernel to calculate the energy.
     * 
     * @param context    the context in which to execute this kernel
     * @return the potential energy due to the AmoebaMultipoleForce
     */
    double executeEnergy(ContextImpl& context);
private:
    AmoebaCudaData& data;
    System& system;
};

/**
 * This kernel is invoked to calculate the vdw forces acting on the system and the energy of the system.
 */
class CudaCalcAmoebaVdwForceKernel : public CalcAmoebaVdwForceKernel {
public:
    CudaCalcAmoebaVdwForceKernel(std::string name, const Platform& platform, AmoebaCudaData& data, System& system);
    ~CudaCalcAmoebaVdwForceKernel();
    /**
     * Initialize the kernel.
     * 
     * @param system     the System this kernel will be applied to
     * @param force      the AmoebaMultipoleForce this kernel will be used for
     */
    void initialize(const System& system, const AmoebaVdwForce& force);
    /**
     * Execute the kernel to calculate the forces.
     * 
     * @param context    the context in which to execute this kernel
     */
    void executeForces(ContextImpl& context);
    /**
     * Execute the kernel to calculate the energy.
     * 
     * @param context    the context in which to execute this kernel
     * @return the potential energy due to the AmoebaMultipoleForce
     */
    double executeEnergy(ContextImpl& context);
private:
    AmoebaCudaData& data;
    System& system;
};

/**
 * This kernel is invoked to calculate the WCA dispersion forces acting on the system and the energy of the system.
 */
class CudaCalcAmoebaWcaDispersionForceKernel : public CalcAmoebaWcaDispersionForceKernel {
public:
    CudaCalcAmoebaWcaDispersionForceKernel(std::string name, const Platform& platform, AmoebaCudaData& data, System& system);
    ~CudaCalcAmoebaWcaDispersionForceKernel();
    /**
     * Initialize the kernel.
     * 
     * @param system     the System this kernel will be applied to
     * @param force      the AmoebaMultipoleForce this kernel will be used for
     */
    void initialize(const System& system, const AmoebaWcaDispersionForce& force);
    /**
     * Execute the kernel to calculate the forces.
     * 
     * @param context    the context in which to execute this kernel
     */
    void executeForces(ContextImpl& context);
    /**
     * Execute the kernel to calculate the energy.
     * 
     * @param context    the context in which to execute this kernel
     * @return the potential energy due to the AmoebaMultipoleForce
     */
    double executeEnergy(ContextImpl& context);
private:
    AmoebaCudaData& data;
    System& system;
};

} // namespace OpenMM

#endif /*AMOEBA_OPENMM_CUDAKERNELS_H*/