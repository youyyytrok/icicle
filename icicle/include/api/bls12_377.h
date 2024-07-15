// WARNING: This file is auto-generated by a script.
// Any changes made to this file may be overwritten.
// Please modify the code generation script instead.
// Path to the code generation script: scripts/gen_c_api.py

#pragma once
#ifndef BLS12_377_API_H
#define BLS12_377_API_H

#include <cuda_runtime.h>
#include "gpu-utils/device_context.cuh"
#include "merkle-tree/merkle.cuh"
#include "matrix/matrix.cuh"
#include "curves/params/bls12_377.cuh"
#include "ntt/ntt.cuh"
#include "msm/msm.cuh"
#include "vec_ops/vec_ops.cuh"
#include "poseidon/poseidon.cuh"

extern "C" cudaError_t bls12_377_g2_precompute_msm_bases_cuda(
  bls12_377::g2_affine_t* bases,
  int msm_size,
  msm::MSMConfig& config,
  bls12_377::g2_affine_t* output_bases);

extern "C" cudaError_t bls12_377_g2_msm_cuda(
  const bls12_377::scalar_t* scalars, const bls12_377::g2_affine_t* points, int msm_size, msm::MSMConfig& config, bls12_377::g2_projective_t* out);

extern "C" cudaError_t bls12_377_precompute_msm_bases_cuda(
  bls12_377::affine_t* bases,
  int msm_size,
  msm::MSMConfig& config,
  bls12_377::affine_t* output_bases);

extern "C" cudaError_t bls12_377_msm_cuda(
  const bls12_377::scalar_t* scalars, const bls12_377::affine_t* points, int msm_size, msm::MSMConfig& config, bls12_377::projective_t* out);

extern "C" bool bls12_377_g2_eq(bls12_377::g2_projective_t* point1, bls12_377::g2_projective_t* point2);

extern "C" void bls12_377_g2_to_affine(bls12_377::g2_projective_t* point, bls12_377::g2_affine_t* point_out);

extern "C" void bls12_377_g2_generate_projective_points(bls12_377::g2_projective_t* points, int size);

extern "C" void bls12_377_g2_generate_affine_points(bls12_377::g2_affine_t* points, int size);

extern "C" cudaError_t bls12_377_g2_affine_convert_montgomery(
  bls12_377::g2_affine_t* d_inout, size_t n, bool is_into, device_context::DeviceContext& ctx);

extern "C" cudaError_t bls12_377_g2_projective_convert_montgomery(
  bls12_377::g2_projective_t* d_inout, size_t n, bool is_into, device_context::DeviceContext& ctx);

extern "C" cudaError_t bls12_377_ecntt_cuda(
  const bls12_377::projective_t* input, int size, ntt::NTTDir dir, ntt::NTTConfig<bls12_377::scalar_t>& config, bls12_377::projective_t* output);

extern "C" bool bls12_377_eq(bls12_377::projective_t* point1, bls12_377::projective_t* point2);

extern "C" void bls12_377_to_affine(bls12_377::projective_t* point, bls12_377::affine_t* point_out);

extern "C" void bls12_377_generate_projective_points(bls12_377::projective_t* points, int size);

extern "C" void bls12_377_generate_affine_points(bls12_377::affine_t* points, int size);

extern "C" cudaError_t bls12_377_affine_convert_montgomery(
  bls12_377::affine_t* d_inout, size_t n, bool is_into, device_context::DeviceContext& ctx);

extern "C" cudaError_t bls12_377_projective_convert_montgomery(
  bls12_377::projective_t* d_inout, size_t n, bool is_into, device_context::DeviceContext& ctx);

extern "C" cudaError_t bls12_377_build_merkle_tree(
  const bls12_377::scalar_t* leaves,
  bls12_377::scalar_t* digests,
  unsigned int height,
  unsigned int input_block_len, 
  const hash::Hasher<bls12_377::scalar_t, bls12_377::scalar_t>* compression,
  const hash::Hasher<bls12_377::scalar_t, bls12_377::scalar_t>* bottom_layer,
  const merkle_tree::TreeBuilderConfig& tree_config);

  extern "C" cudaError_t bls12_377_mmcs_commit_cuda(
    const matrix::Matrix<bls12_377::scalar_t>* leaves,
    unsigned int number_of_inputs,
    bls12_377::scalar_t* digests,
    const hash::Hasher<bls12_377::scalar_t, bls12_377::scalar_t>* hasher,
    const hash::Hasher<bls12_377::scalar_t, bls12_377::scalar_t>* compression,
    const merkle_tree::TreeBuilderConfig& tree_config);

extern "C" cudaError_t bls12_377_poseidon_create_cuda(
  poseidon::Poseidon<bls12_377::scalar_t>** poseidon,
  unsigned int arity,
  unsigned int alpha,
  unsigned int partial_rounds,
  unsigned int full_rounds_half,
  const bls12_377::scalar_t* round_constants,
  const bls12_377::scalar_t* mds_matrix,
  const bls12_377::scalar_t* non_sparse_matrix,
  const bls12_377::scalar_t* sparse_matrices,
  const bls12_377::scalar_t domain_tag,
  device_context::DeviceContext& ctx);

extern "C" cudaError_t bls12_377_poseidon_load_cuda(
  poseidon::Poseidon<bls12_377::scalar_t>** poseidon,
  unsigned int arity,
  device_context::DeviceContext& ctx);

extern "C" cudaError_t bls12_377_poseidon_hash_many_cuda(
  const poseidon::Poseidon<bls12_377::scalar_t>* poseidon,
  const bls12_377::scalar_t* inputs,
  bls12_377::scalar_t* output,
  unsigned int number_of_states,
  unsigned int input_block_len,
  unsigned int output_len,
  hash::HashConfig& cfg);

extern "C" cudaError_t
  bls12_377_poseidon_delete_cuda(poseidon::Poseidon<bls12_377::scalar_t>* poseidon);

extern "C" cudaError_t bls12_377_mul_cuda(
  bls12_377::scalar_t* vec_a, bls12_377::scalar_t* vec_b, int n, vec_ops::VecOpsConfig& config, bls12_377::scalar_t* result);

extern "C" cudaError_t bls12_377_add_cuda(
  bls12_377::scalar_t* vec_a, bls12_377::scalar_t* vec_b, int n, vec_ops::VecOpsConfig& config, bls12_377::scalar_t* result);

extern "C" cudaError_t bls12_377_accumulate_cuda(
  bls12_377::scalar_t* vec_a, bls12_377::scalar_t* vec_b, int n, vec_ops::VecOpsConfig& config);

extern "C" cudaError_t bls12_377_sub_cuda(
  bls12_377::scalar_t* vec_a, bls12_377::scalar_t* vec_b, int n, vec_ops::VecOpsConfig& config, bls12_377::scalar_t* result);

extern "C" cudaError_t bls12_377_transpose_matrix_cuda(
  const bls12_377::scalar_t* input,
  uint32_t row_size,
  uint32_t column_size,
  bls12_377::scalar_t* output,
  device_context::DeviceContext& ctx,
  bool on_device,
  bool is_async);

extern "C" cudaError_t bls12_377_bit_reverse_cuda(
  const bls12_377::scalar_t* input, uint64_t n, vec_ops::BitReverseConfig& config, bls12_377::scalar_t* output);


extern "C" void bls12_377_generate_scalars(bls12_377::scalar_t* scalars, int size);

extern "C" cudaError_t bls12_377_scalar_convert_montgomery(
  bls12_377::scalar_t* d_inout, size_t n, bool is_into, device_context::DeviceContext& ctx);

extern "C" cudaError_t bls12_377_initialize_domain(
  bls12_377::scalar_t* primitive_root, device_context::DeviceContext& ctx, bool fast_twiddles_mode);

extern "C" cudaError_t bls12_377_ntt_cuda(
  const bls12_377::scalar_t* input, int size, ntt::NTTDir dir, ntt::NTTConfig<bls12_377::scalar_t>& config, bls12_377::scalar_t* output);

extern "C" cudaError_t bls12_377_release_domain(device_context::DeviceContext& ctx);

#endif